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
			MyGraph graph(0, 0, 1, 1, 3, 3);
			v1->isWall = true;
			Assert::IsTrue((graph.AddEdge(v1,v2) == 0)); // Should return true
		}

		TEST_METHOD(TestFillAdjacency)
		{
			MyGraph graph(0, 0, 3, 3, 3, 3);

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

			Assert::IsTrue((graph.adjMatrix[2][1] == 1));
			
			
		}
	};

		
}
