#include "pch.h"
#include "CppUnitTest.h"
#include "../Project2/Vertex.h";
#include "../Project2/MyGraph.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
__declspec(dllimport) int AddEdge();
__declspec(dllimport) bool GetNextPosition(int& xpos, int& ypos);

__declspec(dllimport) MyGraph;
__declspec(dllimport) Vertex;
namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(TestAddEdge)
		{
			Vertex* v1 = new Vertex(0, 0);
			Vertex* v2 = new Vertex(0, 1);

			int** pMazeData = new int* [3];
			for (size_t i = 0; i < 3; i++)
			{
				pMazeData[i] = new int[3];
			}
			for (size_t i = 0; i < 3; i++)
			{
				for (size_t j = 0; j < 3; j++)
				{
					pMazeData[i][j] = 0;
				}
			}
			
			//MyGraph graph(0, 0, 1, 1, 3, 3,pMazeData);
			MyGraph graph(0, 0, 1, 1, 3, 3);
			v1->isWall = true;
			Assert::IsTrue((graph.AddEdge(v1,v2) == 0)); // Should return true
		}

		TEST_METHOD(TestFillAdjacency)
		{
			int** pMazeData = new int* [3];
			for (size_t i = 0; i < 3; i++)
			{
				pMazeData[i] = new int[3];
			}
			for (size_t i = 0; i < 3; i++)
			{
				for (size_t j = 0; j < 3; j++)
				{
					pMazeData[i][j] = 0;
				}
			}

			//MyGraph graph(0, 0, 1, 1, 3, 3,pMazeData);
			MyGraph graph(0, 0, 1, 1, 3, 3);

			graph.AddVertex(new Vertex(0, 0));
			graph.AddVertex(new Vertex(0, 1));
			graph.AddVertex(new Vertex(0, 2));
			graph.AddVertex(new Vertex(1, 0));
			graph.AddVertex(new Vertex(1, 1));
			graph.AddVertex(new Vertex(1, 2));
			graph.AddVertex(new Vertex(2, 0));
			graph.AddVertex(new Vertex(2, 1));
			graph.AddVertex(new Vertex(2, 2));

			graph.FillAdjMatrix();

			Assert::IsTrue((graph.adjMatrix[4][5] == 1)); // Should work
			
			
		}

		TEST_METHOD(AssignHeuristic)
		{
			MyGraph graph(0, 0, 2, 2, 4, 4);

			try 
			{
				graph.AssignHeuristic(new Vertex(1, 0));
			}
			catch (const std::exception&)
			{
				Assert::Fail(L"Assign Heuristic is not correct");
			}
		}

		TEST_METHOD(TestFindVertex)
		{
			MyGraph graph(0, 0, 1, 1, 3, 3);

			graph.AddVertex(new Vertex(0, 0));
			graph.AddVertex(new Vertex(0, 1));
			graph.AddVertex(new Vertex(0, 2));
			graph.AddVertex(new Vertex(1, 0));
			graph.AddVertex(new Vertex(1, 1));
			graph.AddVertex(new Vertex(1, 2));
			graph.AddVertex(new Vertex(2, 0));
			graph.AddVertex(new Vertex(2, 1));
			graph.AddVertex(new Vertex(2, 2));

			graph.FillAdjMatrix();
			
			Vertex* possibleNeighbor = graph.FindVertex(3, 3);

			Assert::IsTrue(possibleNeighbor == nullptr);
		}

		TEST_METHOD(TestBuildPath)
		{
			MyGraph graph(0, 0, 1, 1, 3, 3);

			graph.AddVertex(new Vertex(0, 0));
			graph.AddVertex(new Vertex(0, 1));
			graph.AddVertex(new Vertex(0, 2));
			graph.AddVertex(new Vertex(1, 0));
			graph.AddVertex(new Vertex(1, 1));
			graph.AddVertex(new Vertex(1, 2));
			graph.AddVertex(new Vertex(2, 0));
			graph.AddVertex(new Vertex(2, 1));
			graph.AddVertex(new Vertex(2, 2));

			graph.FillAdjMatrix();

			try
			{
				vector<Vertex*> path = graph.buildPath();
			}
			catch (const std::exception&)
			{
				Assert::Fail(L"Build path is not correct");
			}


		}

		TEST_METHOD(TestGetNextPos)
		{
			int** pMazeData = new int* [3];
			for (size_t i = 0; i < 3; i++)
			{
				pMazeData[i] = new int[3];
			}
			for (size_t i = 0; i < 3; i++)
			{
				for (size_t j = 0; j < 3; j++)
				{
					pMazeData[i][j] = 0;
				}
			}

			//MyGraph graph(0, 0, 1, 1, 3, 3,pMazeData);
			MyGraph graph(0, 0, 1, 1, 3, 3);

			graph.AddVertex(new Vertex(0, 0));
			graph.AddVertex(new Vertex(0, 1));
			graph.AddVertex(new Vertex(0, 2));
			graph.AddVertex(new Vertex(1, 0));
			graph.AddVertex(new Vertex(1, 1));
			graph.AddVertex(new Vertex(1, 2));
			graph.AddVertex(new Vertex(2, 0));
			graph.AddVertex(new Vertex(2, 1));
			graph.AddVertex(new Vertex(2, 2));

			graph.FillAdjMatrix();

			vector<Vertex*> Path;
			int xpos = 2;
			int ypos = 1;

			try
			{
				GetNextPosition(xpos, ypos);
			}
			catch (const std::exception&)
			{
				Assert::Fail(L"Get Next Pos is not correct");
			}
		}

		TEST_METHOD(TestAStar)
		{
			int** pMazeData = new int* [3];
			for (size_t i = 0; i < 3; i++)
			{
				pMazeData[i] = new int[3];
			}
			for (size_t i = 0; i < 3; i++)
			{
				for (size_t j = 0; j < 3; j++)
				{
					pMazeData[i][j] = 0;
				}
			}

			MyGraph graph(0, 0, 1, 1, 3, 3);

			graph.AddVertex(new Vertex(0, 0));
			graph.AddVertex(new Vertex(0, 1));
			graph.AddVertex(new Vertex(0, 2));
			graph.AddVertex(new Vertex(1, 0));
			graph.AddVertex(new Vertex(1, 1));
			graph.AddVertex(new Vertex(1, 2));
			graph.AddVertex(new Vertex(2, 0));
			graph.AddVertex(new Vertex(2, 1));
			graph.AddVertex(new Vertex(2, 2));

			graph.FillAdjMatrix();

			try
			{
				graph.AStar();
			}
			catch (const std::exception&)
			{
				Assert::Fail(L"A star is not correct");
			}
		}
	};

		
}
