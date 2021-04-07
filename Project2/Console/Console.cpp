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
__declspec(dllimport) void PrintMatrix();
using namespace std;
int main()
{
	/**

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
		 *
	 */
	/**
	 * 
	 */

	int** data = new int* [5];
	for(int i=0;i<5;i++)
	{
		data[i] = new int[5];
	}
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			data[i][j] =  1;
		}
	}

	//Test case 1 in DLL
	/**

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << data[i][j];
		}
		cout << endl;
	}

	SetMaze((const int**)data, 5, 5);
	SetStart(0, 0);
	SetEnd(4, 3);
	int x = int(5);
	int y = 5;
	while (GetNextPosition(x, y))
	{

		cout << x << y << endl;
	}
		 * 
	 */


	//Test case 2 in DLL
	data[0][0] = 0;
	data[4][0] = 0;
	data[2][1] = 0;
	data[4][1] = 0;
	data[0][2] = 0;
	data[1][2] = 0;
	data[4][2] = 0;
	data[0][3] = 0;
	data[1][3] = 0;
	data[3][3] = 0;
	data[0][4] = 0;
	data[1][4] = 0;

	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout << data[i][j];
		}
		cout << endl;
	}
	
	SetMaze((const int**) data, 5, 5);
	SetStart(0, 1);
	SetEnd(4, 3);
	int x = int(5);
	int y = 5;
	while(GetNextPosition(x, y))
	{
		
		cout << x << y << endl;
	}
	
}
