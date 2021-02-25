// Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
__declspec(dllimport) char* GetTeam();
__declspec(dllimport) void SetStart(int xpos, int ypos);
__declspec(dllimport) void SetEnd(int xpos, int ypos);
__declspec(dllimport) void GetStart(int& xpos, int& ypos);
__declspec(dllimport) void GetEnd(int& xpos, int& ypos);
__declspec(dllimport) int** GetMaze(int& width, int& height);
__declspec(dllimport) void SetMaze(const int** data, int width, int height);
__declspec(dllimport) void GetNextPosition(int& xpos, int& ypos);
using namespace std;
int main()
{
    std::cout << GetTeam();
	/**
	
	int width = 10;
	const int** testMazePointer = new const int* [width];

	for (size_t i = 0; i < 10; i++)
	{
		testMazePointer[i] = new int(1);
	}
	testMazePointer[2, 2] = new int(11);
	SetMaze(testMazePointer, width, width);

	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			cout << &testMazePointer[i][j]<< i << j <<endl;
		}
	}
	int** returnedMaze = GetMaze(width, width);
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			cout << &returnedMaze[i][j] << i << j << endl;
		}
	}
	*/

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
