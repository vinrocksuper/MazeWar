#include "pch.h"

int mazeWidth;
int mazeHeight;
int** pMazeData;
bool startSet = false;
int startX;
int startY;
bool endSet = false;
int endX;
int endY;
int currentX;
int currentY;

// Returns string of team members name
__declspec(dllexport) char* GetTeam() {
	return (char*)"Vincent Li and Duy Vu";
}

// Sets maze data from main into the dll. Save into a variable in the DLL. Use this for GetData function.
__declspec(dllexport) void SetMaze(const int** data, int width, int height) {

	pMazeData = new int* [height];
	for (size_t i = 0; i < height; i++)
	{
		pMazeData[i] = (int*)data[i];
	}
	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < width; j++)
		{
			pMazeData[i][j] = (int)data[i][j];
		}
	}
	mazeWidth = width;
	mazeHeight = height;

}

// Gets maze data that was passed in using SetMaze function and the width/height using set arguments
__declspec(dllexport) int** GetMaze(int& width, int& height) {
	width = mazeWidth;
	height = mazeHeight;
	return pMazeData;
}

// returns next x/y pos to move to. 
__declspec(dllexport) void GetNextPosition(int& xpos, int& ypos) {
	xpos = 5;
	ypos = 5;
}

// sets starting location for player. Saves the x and y values for starting pos
__declspec(dllexport) void SetStart(int xpos, int ypos) {
	startX = xpos;
	startY = ypos;
	startSet = true;
}

// gets the starting position for the player. If x and y havent been set yet, return -1 for both
__declspec(dllexport) void GetStart(int& xpos, int& ypos) {
	if (startSet) {
		xpos = startX;
		ypos = startY;
	}
	else {
		xpos = -1;
		ypos = -1;
	}
}

// Sets end pos for player. saves x and y location
__declspec(dllexport) void SetEnd(int xpos, int ypos) {
	endX = xpos;
	endY = ypos;
	endSet = true;
}

// Gets the end location for player. Returns saved x/y loc. If not set, return -1 for both.
__declspec(dllexport) void GetEnd(int& xpos, int& ypos) {
	if (endSet) {
		xpos = endX;
		ypos = endY;
	}
	else {
		xpos = -1;
		ypos = -1;
	}
}
