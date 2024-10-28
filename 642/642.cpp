/*
Рекурсивний спосіб

*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double getMaxAbsoluteElementRec(const double* arr, int size, int index = 0, double maxElement = 0) {
    if (index == size) return maxElement;
    if (fabs(arr[index]) > maxElement) maxElement = fabs(arr[index]);
    return getMaxAbsoluteElementRec(arr, size, index + 1, maxElement);
}

int findFirstPositiveIndexRec(const double* arr, int size, int index = 0) {
    if (index == size) return -1;
    if (arr[index] > 0) return index;
    return findFirstPositiveIndexRec(arr, size, index + 1);
}

int findSecondPositiveIndexRec(const double* arr, int size, int firstPos, int index = 0) {
    if (index <= firstPos) return findSecondPositiveIndexRec(arr, size, firstPos, index + 1);
    if (index == size || arr[index] > 0) return index;
    return findSecondPositiveIndexRec(arr, size, firstPos, index + 1);
}

double calculateSumBetweenPositivesRec(const double* arr, int firstPos, int secondPos, int index) {
    if (index >= secondPos) return 0;
    return arr[index] + calculateSumBetweenPositivesRec(arr, firstPos, secondPos, index + 1);
}

void moveNonZeroElementsRec(double* arr, int size, int index, int& nonZeroIndex) {
    if (index == size) return;
    if (arr[index] != 0) arr[nonZeroIndex++] = arr[index];
    moveNonZeroElementsRec(arr, size, index + 1, nonZeroIndex);
}

void fillRemainingZerosRec(double* arr, int size, int nonZeroIndex) {
    if (nonZeroIndex == size) return;
    arr[nonZeroIndex++] = 0;
    fillRemainingZerosRec(arr, size, nonZeroIndex);
}

void printArrayRec(const double* arr, int size, int index = 0) {
    if (index == size) {
        cout << endl;
        return;
    }
    cout << fixed << setprecision(2) << arr[index] << " ";
    printArrayRec(arr, size, index + 1);
}

int main() {
    int n;
    cout << "Enter array: ";
    cin >> n;

    double* arr = new double[n];
    for (int i = 0; i < n; ++i) {
        cout << "Number " << (i + 1) << ": "; 
        cin >> arr[i];
    }

    cout << "Original array: ";
    printArrayRec(arr, n);

    double maxAbs = getMaxAbsoluteElementRec(arr, n);
    cout << "Max: " << fixed << setprecision(2) << maxAbs << endl;

    int firstPos = findFirstPositiveIndexRec(arr, n);
    int secondPos = findSecondPositiveIndexRec(arr, n, firstPos);
    double sum = firstPos != -1 && secondPos != -1 ? calculateSumBetweenPositivesRec(arr, firstPos, secondPos, firstPos + 1) : 0;
    cout << "Sum: " << fixed << setprecision(2) << sum << endl;

    int nonZeroIndex = 0;
    moveNonZeroElementsRec(arr, n, 0, nonZeroIndex);
    fillRemainingZerosRec(arr, n, nonZeroIndex);

    cout << "Modified array: ";
    printArrayRec(arr, n);

    delete[] arr;
    return 0;
}
