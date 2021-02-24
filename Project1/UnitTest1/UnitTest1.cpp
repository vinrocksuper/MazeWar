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

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestTeamName)
		{
			Assert::IsTrue(strcmp(GetTeam(), "Ben") == 0);
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

	};
}
