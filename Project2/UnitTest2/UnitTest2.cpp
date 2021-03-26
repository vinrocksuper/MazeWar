#include "pch.h"
#include "CppUnitTest.h"
#include "../Project2/Graph.h"
#include "../Project2/Vertex.h";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

__declspec(dllimport) int AddEdge(Vertex* vert1, Vertex* vert2);
__declspec(dllimport) void FillAdjMatrix();

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(TestAddEdge)
		{
			Vertex* v1 = new Vertex(0, 0);
			Vertex* v2 = new Vertex(0, 1);
			v1->isWall = true;
			Assert::IsTrue(AddEdge(v1, v2) == 0); // Should return true
		}
	};
}
