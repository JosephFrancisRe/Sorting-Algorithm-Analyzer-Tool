#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include "quickSort.h"
#include "printFunctions.h"

using namespace std;

extern bool printArrays;

int partition(vector<int>& array, int s, int f, double& swapCounter, double& comparisonCounter) {

    int pivot = array[s];

    int count = 0;
    for (int i = s + 1; i <= f; i++) {
        comparisonCounter++;
        if (array[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = s + count;
    swap(array[pivotIndex], array[s]);
    swapCounter++;

    // Sorting left and right parts of the pivot element
    int i = s, j = f;

    while (i < pivotIndex && j > pivotIndex) {

        while (array[i] <= pivot) {
            comparisonCounter++;
            i++;
        }

        while (array[j] > pivot) {
            comparisonCounter++;
            j--;
        }

        comparisonCounter++;
        if (i < pivotIndex && j > pivotIndex) {
            swap(array[i++], array[j--]);
            swapCounter++;
        }
    }

    return pivotIndex;
}

void quickSort(vector<int>& array, int s, int f, double& swapCounter, double& comparisonCounter)
{
    if (s >= f) {
        return;
    }

    int partIndex = partition(array, s, f, swapCounter, comparisonCounter);
    quickSort(array, s, partIndex - 1, swapCounter, comparisonCounter);
    quickSort(array, partIndex + 1, f, swapCounter, comparisonCounter);
}

void quickSortContainer(vector<int> array) {
    double worstCaseComparisons = ((pow(array.size(), 2.0) - array.size()) / 2.0);
    double bestCaseComparisons = (array.size() - 1);
    double comparisonCounter = 0;

    double worstCaseSwaps = ((pow(array.size(), 2.0) - array.size()) / 2.0);
    double bestCaseSwaps = 0;
    double swapCounter = 0;

    quickSort(array, 0, array.size() - 1, swapCounter, comparisonCounter);

    printResults(array, 5, bestCaseComparisons, worstCaseComparisons, comparisonCounter, worstCaseSwaps, bestCaseSwaps, swapCounter);
}