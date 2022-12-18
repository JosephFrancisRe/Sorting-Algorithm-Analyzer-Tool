#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include "bubbleSort.h"
#include "printFunctions.h"

using namespace std;

extern bool printArrays;

void bubbleSort(vector<int> array) {
	double worstCaseComparisons = ((pow(array.size(), 2.0) - array.size()) / 2.0);
	double bestCaseComparisons = (array.size() - 1);
	double comparisonCounter = 0;

	double worstCaseSwaps = ((pow(array.size(), 2.0) - array.size()) / 2.0);
	double bestCaseSwaps = 0;
	double swapCounter = 0;

	for (int i = 0; i < array.size() - 1; i++) {
		for (int j = 0; j < array.size() - i - 1; j++) {
			comparisonCounter++;
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapCounter++;
			}
		}

		if (swapCounter == 0) {
			break;
		}
	}

	printResults(array, 3, bestCaseComparisons, worstCaseComparisons, comparisonCounter, worstCaseSwaps, bestCaseSwaps, swapCounter);
}