#include "pch.h"
#include "CppUnitTest.h"
#include "../Project2/Vertex.h";
#include "../Project2/MyGraph.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
__declspec(dllimport) int AddEdge();

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

		// UNFINSHED!!
		TEST_METHOD(RemoveVertex)
		{
			try 
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

				// set up the maze and fill matrix
				// Did I miss something before call the remove vertex?

				//graph.RemoveVertex();
			}
			catch (const std::exception&)
			{
				Assert::Fail(L"Remove Vertex is not correct");
			}
		}

		TEST_METHOD(FindVertex)
		{
			MyGraph graph(0, 0, 1, 1, 3, 3);
			try
			{
				graph.FindVertex(1);
			}
			catch (const std::exception&)
			{
				Assert::Fail(L"Find Vertex is not correct");
			}
		}

		TEST_METHOD(BuildPath)
		{

		}

		TEST_METHOD(PrintMatrix)
		{

		}

		TEST_METHOD(PrintNode)
		{

		}
	};

		
}
