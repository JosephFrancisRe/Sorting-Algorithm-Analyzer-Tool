#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include "selectionSort.h"
#include "printFunctions.h"

using namespace std;

void selectionSort(vector<int> array) {
	double worstCaseComparisons = ((pow(array.size(), 2.0) - array.size()) / 2.0);
	double bestCaseComparisons = ((pow(array.size(), 2.0) - array.size()) / 2.0);
	double comparisonCounter = 0;

	double worstCaseSwaps = (array.size() - 1);
	double bestCaseSwaps = 0;
	double swapCounter = 0;

	int minIndex;

	for (int i = 0; i < array.size() - 1; i++) {
		minIndex = i;
		for (int j = i + 1; j < array.size(); j++) {
			comparisonCounter++;
			if (array[j] < array[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			int temp = array[i];
			array[i] = array[minIndex];
			array[minIndex] = temp;
			swapCounter++;
		}
	}

	printResults(array, 2, bestCaseComparisons, worstCaseComparisons, comparisonCounter, worstCaseSwaps, bestCaseSwaps, swapCounter);
}