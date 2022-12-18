#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include "insertionSort.h"
#include "printFunctions.h"

using namespace std;

extern bool printArrays;

void insertionSort(vector<int> array) {
	double worstCaseComparisons = ((pow(array.size(), 2.0) - array.size())/2.0);
	double bestCaseComparisons = (array.size() - 1);
	double comparisonCounter = 0;

	double worstCaseSwaps = ((pow(array.size(), 2.0) - array.size()) / 2.0);
	double bestCaseSwaps = 0;
	double swapCounter = 0;
	
	for (int i = 1; i < array.size(); i++) {
		for (int j = i; j >= 1; j--) {
			comparisonCounter++;
			if (array[j] < array[j - 1]) {
				int temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
				swapCounter++;
			}
			else {
				break;
			}
		}
	}

	printResults(array, 1, bestCaseComparisons, worstCaseComparisons, comparisonCounter, worstCaseSwaps, bestCaseSwaps, swapCounter);
}