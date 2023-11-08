#include "pch.h"
#include "CppUnitTest.h"
#include "..\main.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			int number = 1;
			int** a = new int* [3];
			for (int i = 0; i < 3; i++)
			{
				a[i] = new int[3];
			}
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					a[i][j] = number++;
				}
			}
			//{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			SwapElements(a, 3, 0, 0, 1);
			Assert::AreEqual(a[1][1], 1);

			for (int i = 0; i < 3; i++)
			{
				delete[] a[i];
			}
			delete[] a;
		}
	};
}
