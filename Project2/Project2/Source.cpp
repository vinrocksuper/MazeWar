#include "pch.h"
#include <stdlib.h>
#include "Vertex.h"
#include "MyGraph.h"

int mazeWidth;
int mazeHeight;
int** pMazeData;
bool startSet = false;
int startX;
int startY;
bool endSet = false;
int endX;
int endY;
int xPath[] = { 0,1,2,2,2,2,2,3,4,5 };
int yPath[] = { 0,0,0,1,2,3,4,4,4,4 };
int currentStep = 0;
bool mazeSet = false;
bool init = false;
MyGraph graph(startX, startY, endX, endY, mazeWidth, mazeHeight);
vector<Vertex*> solvedPath;

// Returns string of team members name
__declspec(dllexport) char* GetTeam() {
	return (char*)"Vincent Li and Duy Vu and Curry Li";
}

// Sets maze data from main into the dll. Save into a variable in the DLL. Use this for GetData function.
__declspec(dllexport) bool SetMaze(const int** data, int width, int height) {

	if(width <= 0 || height <= 0)
	{
		return mazeSet;
	}
	
	pMazeData = new int* [width];
	for (size_t i = 0; i < width; i++)
	{
		pMazeData[i] = new int[height];
	}
	for (size_t i = 0; i < width; i++)
	{
		for (size_t j = 0; j < height; j++)
		{
			pMazeData[i][j] = (int)data[i][j];
			if((int)data[i][j] ==0)
			{
				graph.AddVertex(new Vertex(i, j));
			}
			
		}
	}
	mazeWidth = width;
	mazeHeight = height;
	graph.SetDimensions(width, height);
	mazeSet = true;
	graph.setupMatrix();


	
	return mazeSet;
}

// Gets maze data that was passed in using SetMaze function and the width/height using set arguments
__declspec(dllexport) int** GetMaze(int& width, int& height) {
	width = mazeWidth;
	height = mazeHeight;
	if(mazeSet)
	{
		return pMazeData;
	}
	return nullptr;
}

// returns next x/y pos to move to. 
__declspec(dllexport) bool GetNextPosition(int& xpos, int& ypos) {
	if (solvedPath.empty())
	{
		graph.SetStart(startX, startY);
		graph.SetEnd(endX, endY);
		for (auto&& v : graph.vertices)
		{
			graph.AssignHeuristic(v);
		}
		graph.printNodes();
		graph.AStar();
		solvedPath = graph.buildPath();
		currentStep = solvedPath.size()-1;
	}
	if(currentStep > solvedPath.size())
	{
		return false;
	}
	if(solvedPath[currentStep])
	{
		xpos = solvedPath[currentStep]->xPos;
		ypos = solvedPath[currentStep]->yPos;
		currentStep--;
		return true;
	}
	return false;
}

// sets starting location for player. Saves the x and y values for starting pos
__declspec(dllexport) bool SetStart(int xpos, int ypos) {
	if(xpos <0 || ypos <0 || xpos >= mazeWidth || ypos >= mazeHeight)
	{
		return false;
	}
	startX = xpos;
	startY = ypos;
	graph.SetStart(startX, startY);
	startSet = true;
	return true;
}

// gets the starting position for the player. If x and y havent been set yet, return -1 for both
__declspec(dllexport) bool GetStart(int& xpos, int& ypos) {
	if (startSet) {
		xpos = startX;
		ypos = startY;
		return true;
	}
	else {
		return false;
	}
}

// Sets end pos for player. saves x and y location
__declspec(dllexport) bool SetEnd(int xpos, int ypos) {
	if (xpos < 0 || ypos < 0 || xpos >= mazeWidth || ypos >= mazeHeight)
	{
		return false;
	}
	endX = xpos;
	endY = ypos;
	graph.SetEnd(startX, startY);
	endSet = true;
	return true;
}

// Gets the end location for player. Returns saved x/y loc. If not set, return -1 for both.
__declspec(dllexport) bool GetEnd(int& xpos, int& ypos) {
	if (endSet) {
		xpos = endX;
		ypos = endY;
		return true;
	}
	else {
		return false;
	}
}

// Brings player back to their start location and run thru the maze again
__declspec(dllexport) bool Restart()
{
	currentStep = solvedPath.size() - 1;
	return true;
}

__declspec(dllexport) int AddEdge()
{
	Vertex* v1 = new Vertex(0, 9);
	Vertex* v2 = new Vertex(0, 8);
	v2->isWall = true;
	if(v1->isWall || v2->isWall)
	{
		return 0;
	}
	return 1;
}

__declspec(dllexport) void PrintMatrix()
{
	graph.printMatrix();
}