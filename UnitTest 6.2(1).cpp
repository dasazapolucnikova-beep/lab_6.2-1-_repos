#include "pch.h"
#include "CppUnitTest.h"
#include "../Project 6.2(1)/Project 6.2(1).cpp " 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest621
{
	TEST_CLASS(UnitTest621)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// a[0]=10, a[2]=20, a[4]=30
			// Сума елементів з парними індексами: 10 + 20 + 30 = 60
			int a[5] = { 10, 5, 20, 15, 30 };
			int expectedSum = 60;

			int actualSum = SumEvenIndicesRec(a, 5);

			Assert::AreEqual(expectedSum, actualSum);
		
		}
	};
}
