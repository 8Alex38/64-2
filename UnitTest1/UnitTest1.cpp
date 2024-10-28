#include "pch.h"
#include "CppUnitTest.h"
#include "../642/642.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest642
{
    TEST_CLASS(UnitTest642)
    {
    public:

        void CheckEqual(double expected, double result, const char* testName) {
            if (expected == result) {
                cout << testName << " passed." << endl;
            }
            else {
                cout << testName << " failed: expected " << expected << ", got " << result << endl;
            }
        }

        void CheckEqual(int expected, int result, const char* testName) {
            if (expected == result) {
                cout << testName << " passed." << endl;
            }
            else {
                cout << testName << " failed: expected " << expected << ", got " << result << endl;
            }
        }

        TEST_METHOD(TestGetMaxAbsoluteElementRec)
        {
            double arr[] = { -3.5, 2.0, -1.0, 4.6, -2.3 };
            double expected = 4.6;
            double result = getMaxAbsoluteElementRec(arr, 5);
            CheckEqual(expected, result, "TestGetMaxAbsoluteElementRec");
        }

        TEST_METHOD(TestFindFirstPositiveIndexRec)
        {
            double arr[] = { -3.5, -2.0, 1.0, 4.6, -2.3 };
            int expected = 2; 
            int result = findFirstPositiveIndexRec(arr, 5);
            CheckEqual(expected, result, "TestFindFirstPositiveIndexRec");
        }

        TEST_METHOD(TestFindSecondPositiveIndexRec)
        {
            double arr[] = { -3.5, -2.0, 1.0, 4.6, -2.3 };
            int firstPos = findFirstPositiveIndexRec(arr, 5);
            int expected = 3;
            int result = findSecondPositiveIndexRec(arr, 5, firstPos);
            CheckEqual(expected, result, "TestFindSecondPositiveIndexRec");
        }

        TEST_METHOD(TestCalculateSumBetweenPositivesRec)
        {
            double arr[] = { -3.5, -2.0, 1.0, 4.6, -2.3 };
            int firstPos = findFirstPositiveIndexRec(arr, 5);
            int secondPos = findSecondPositiveIndexRec(arr, 5, firstPos);
            double expected = 0.0; 
            double result = calculateSumBetweenPositivesRec(arr, firstPos, secondPos, firstPos + 1);
            CheckEqual(expected, result, "TestCalculateSumBetweenPositivesRec");
        }

        TEST_METHOD(TestMoveNonZeroElementsRec)
        {
            double arr[] = { 0.0, 1.0, 0.0, 2.0, 0.0 };
            int nonZeroIndex = 0;
            moveNonZeroElementsRec(arr, 5, 0, nonZeroIndex);
            CheckEqual(2, nonZeroIndex, "TestMoveNonZeroElementsRec");

            CheckEqual(1.0, arr[0], "TestMoveNonZeroElementsRec Check 1");
            CheckEqual(2.0, arr[1], "TestMoveNonZeroElementsRec Check 2");
        }

        TEST_METHOD(TestFillRemainingZerosRec)
        {
            double arr[5] = { 1.0, 2.0, 0.0, 0.0, 0.0 };
            int nonZeroIndex = 2; 
            fillRemainingZerosRec(arr, 5, nonZeroIndex);

            CheckEqual(0.0, arr[2], "TestFillRemainingZerosRec Check 1");
            CheckEqual(0.0, arr[3], "TestFillRemainingZerosRec Check 2");
            CheckEqual(0.0, arr[4], "TestFillRemainingZerosRec Check 3");
        }
    };
}
