// Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../Project2/Vertex.h";
#include "../Project2/MyGraph.h";

__declspec(dllimport) char* GetTeam();
__declspec(dllimport) bool SetStart(int xpos, int ypos);
__declspec(dllimport) bool SetEnd(int xpos, int ypos);
__declspec(dllimport) bool GetStart(int& xpos, int& ypos);
__declspec(dllimport) bool GetEnd(int& xpos, int& ypos);
__declspec(dllimport) int** GetMaze(int& width, int& height);
__declspec(dllimport) bool SetMaze(const int** data, int width, int height);
__declspec(dllimport) bool GetNextPosition(int& xpos, int& ypos);

using namespace std;
int main()
{
	MyGraph graph(1, 0, 2, 2, 3, 3);

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
	graph.printNodes();
	graph.AStarTest();
	graph.printMatrix();
	vector<Vertex*> printList = graph.buildPath();
	for (auto && print_list : printList)
	{
		cout << print_list->xPos << "," << print_list->yPos << endl;
	}

}
