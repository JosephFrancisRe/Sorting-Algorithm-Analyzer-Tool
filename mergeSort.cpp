#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include "mergeSort.h"
#include "printFunctions.h"

using namespace std;

extern bool printArrays;

void merge(vector<int>& array, int s, int q, int f, double& comparisonCounter) {
	int leftArraySize = q - s + 1;
	int rightArraySize = f - q;

	int sIndexOfLeftArray = 0;
	int sIndexOfRightArray = 0;
	int sIndexOfMergedArray = s;

	int* leftArray = new int[leftArraySize];
	int* rightArray = new int[rightArraySize];

	for (int i = 0; i < leftArraySize; i++) {
		leftArray[i] = array[s + i];
	}

	for (int j = 0; j < rightArraySize; j++) {
		rightArray[j] = array[q + 1 + j];
	}

	for (; sIndexOfLeftArray < leftArraySize && sIndexOfRightArray < rightArraySize;) {
		if (leftArray[sIndexOfLeftArray] <= rightArray[sIndexOfRightArray]) {
			comparisonCounter++;
			array[sIndexOfMergedArray] = leftArray[sIndexOfLeftArray];
			sIndexOfLeftArray++;
		}
		else {
			comparisonCounter++;
			array[sIndexOfMergedArray] = rightArray[sIndexOfRightArray];
			sIndexOfRightArray++;
		}
		sIndexOfMergedArray++;
	}

	for (; sIndexOfLeftArray < leftArraySize; sIndexOfLeftArray++) {
		array[sIndexOfMergedArray] = leftArray[sIndexOfLeftArray];
		sIndexOfMergedArray++;
	}

	for (; sIndexOfRightArray < rightArraySize; sIndexOfRightArray++) {
		array[sIndexOfMergedArray] = rightArray[sIndexOfRightArray];
		sIndexOfMergedArray++;
	}
}

void mergeSort(vector<int>& array, int s, int f, double& comparisonCounter) {
	if (s >= f) {
		return;
	}

	int q = s + (f - s) / 2;
	mergeSort(array, s, q, comparisonCounter);
	mergeSort(array, q + 1, f, comparisonCounter);
	merge(array, s, q, f, comparisonCounter);
}

void mergeSortContainer(vector<int> array) {
	double worstCaseComparisons = ((array.size() * ceil(log2(array.size()))) - (pow(2, ceil(log2(array.size())))) + 1.0);
	double bestCaseComparisons = floor((((array.size() * ceil(log2(array.size()))) - (pow(2, ceil(log2(array.size())))) + 1.0) / 2.0));
	double comparisonCounter = 0;

	mergeSort(array, 0, array.size() - 1, comparisonCounter);

	printResultsNoSwap(array, 4, bestCaseComparisons, worstCaseComparisons, comparisonCounter);
}