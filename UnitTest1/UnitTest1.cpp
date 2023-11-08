#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 7.2_rek/lab 7.3_rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
    public:
        TEST_METHOD(TestMethod1)
        {
            const int n = 20;
            int** a = new int* [n];
            for (int i = 0; i < n; i++) {
                a[i] = new int[n];
            }
            int Low = -9;
            int High = 9;
            Create(a, n, Low, High, 0, 0);
            for (int i = 0; i < n; i++) {
                delete[] a[i];
            }
            delete[] a;
        }
    };
}
