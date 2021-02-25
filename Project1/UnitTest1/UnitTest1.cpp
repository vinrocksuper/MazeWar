#include "pch.h"
#include "CppUnitTest.h"
#include <cstring>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

__declspec(dllimport) char* GetTeam();
__declspec(dllimport) void SetStart(int xpos, int ypos);
__declspec(dllimport) void SetEnd(int xpos, int ypos);
__declspec(dllimport) void GetStart(int& xpos, int& ypos);
__declspec(dllimport) void GetEnd(int& xpos, int& ypos);
__declspec(dllimport) int** GetMaze(int& width, int& height);
__declspec(dllimport) void SetMaze(const int** data, int width, int height);
__declspec(dllimport) void GetNextPosition(int& xpos, int& ypos);

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestTeamName)
		{
			//Assert::IsTrue(strcmp(GetTeam(), "Ben") == 0); Fails bc not equal (strcmp returns 0 if equal)
			Assert::IsTrue(strcmp(GetTeam(), "Vincent Li and Duy Vu") == 0); // Pass bc equal 
			//Assert::IsTrue(strcmp(GetTeam(), "Vincent Li and Duy Vu") == 1); // Fail bc they are equal 
		}

		TEST_METHOD(TestSetStart)
		{
			try {
				SetStart(3, 2);
			}
			catch (const std::exception&) {
				Assert::Fail(L"set start threw exception");
			}
		}

		TEST_METHOD(TestSetEnd)
		{
			try {
				SetEnd(6, 8);
			}
			catch (const std::exception&) {
				Assert::Fail(L"set end threw exception");
			}
		}

		TEST_METHOD(TestGetStart)
		{
			int x = 3;
			int y = 2;
			try {
				GetStart(x, y);
				Assert::IsTrue(x == -1); // Passes bc Not Set Yet so x/y are both going to be set to -1
				// Assert::IsTrue(y == 2); // fails since y = -1 from GetStart
			}
			catch (const std::exception&) {
				Assert::Fail(L"get start threw exception");
			}
		}
		TEST_METHOD(TestGetEnd)
		{
			int x = 3;
			int y = 2;
			try {
				GetEnd(x, y);
				Assert::IsTrue(x == -1); // Both pass
				Assert::IsTrue(y == -1); // 
			}
			catch (const std::exception&) {
				Assert::Fail(L"get start threw exception");
			}
		}

		TEST_METHOD(TestGetMaze)
		{
			int width = 3;
			int height = 2;
			try {
				GetMaze(width, width);
			}
			catch (const std::exception&) {
				Assert::Fail(L"get maze threw exception");
			}
		}
		TEST_METHOD(TestSetMaze) 
		{
			const int** testMazePointer = new const int *[10];

			for (size_t i = 0; i < 10; i++)
			{
				testMazePointer[i] = new int(1);
			}
			testMazePointer[2, 2] = new int(11);

			try {
				SetMaze(testMazePointer, 10, 10);
			}
			catch (const std::exception&) {
				
				for (size_t i = 0; i < 3; i++)
				{
					delete[] testMazePointer[i];
				}
				delete[] testMazePointer;
				

				Assert::Fail(L"set maze threw exception");
			}
			for (size_t i = 0; i < 3; i++)
			{
				delete[] testMazePointer[i];
			}
			delete[] testMazePointer;

		}
		// Incomplete
		TEST_METHOD(TestNextPosition) 
		{
			int** testMaze = new int* [10];
			

			for (size_t i = 0; i < 10; i++)
			{
				testMaze[i] = new int(1);
			}


			for (size_t i = 0; i < 10; i++)
			{
				delete[] testMaze[i];
			}
			delete[] testMaze;

		}
	};
}
