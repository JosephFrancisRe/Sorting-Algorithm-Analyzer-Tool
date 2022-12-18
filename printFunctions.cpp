#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <map>
#include <chrono>
#include <algorithm>
#include "printFunctions.h"

using namespace std;

extern bool printArrays;
extern map<int, string> sortingNames;

map<int, double> comparisonRates;
map<int, double> swapRates;

struct TimeTuple {
	string timeTupleName;
	chrono::steady_clock::time_point timeTupleBegin;
	chrono::steady_clock::time_point timeTupleEnd;

	TimeTuple(string name, chrono::steady_clock::time_point begin, chrono::steady_clock::time_point end) {
		timeTupleName = name;
		timeTupleBegin = begin;
		timeTupleEnd = end;
	}
};

void printPreSortedArray(vector<int> array) {
	if (printArrays == true) {
		cout << "Array before sorting:" << endl;

		printArray(array);

		cout << "The above array will be sorted using a variety of algorithms. The results are printed below." << endl;
	}
}

void printArray(vector<int> array) {
	if (printArrays == true) {
		for (int i = 0; i < array.size(); i++) {
			cout << array[i] << " ";
		}
		cout << endl << endl;
	}
}

void printComparisonResults(double bestCaseComparisons, double worstCaseComparisons, double comparisonCounter) {
	cout << "Best Case Comparisons: " << bestCaseComparisons << endl;
	cout << "Worst Case Comparisons: " << worstCaseComparisons << endl;
	cout << "Actual Comparisons: " << comparisonCounter << endl;
	if ((worstCaseComparisons - bestCaseComparisons) != 0) {
		cout << "Actual comparison efficiency: " << (((abs(comparisonCounter - worstCaseComparisons)) / (worstCaseComparisons - bestCaseComparisons)) * 100) << "%" << endl << endl;
	}
	else {
		cout << "No actual comparison efficiency available as the best case and worst case share the same number of comparisons." << endl << endl;
	}
}

void printSwapResults(double worstCaseSwaps, double bestCaseSwaps, double swapCounter) {
	cout << "Best Case Swaps: " << bestCaseSwaps << endl;
	cout << "Worst Case Swaps: " << worstCaseSwaps << endl;
	cout << "Actual Swaps: " << swapCounter << endl;
	if ((worstCaseSwaps - bestCaseSwaps) != 0) {
		cout << "Actual swap efficiency: " << (((abs(swapCounter - worstCaseSwaps)) / (worstCaseSwaps - bestCaseSwaps)) * 100) << "%" << endl << endl;
	}
	else {
		cout << "No actual swap efficiency available as the best case and worst case share the same number of swaps." << endl << endl;
	}
}

void printDivider() {
	cout << endl << "----------------------------------------------------------" << endl << endl;
}

void printTimeElapsed(chrono::steady_clock::time_point begin, chrono::steady_clock::time_point end) {
	cout << "Time elapsed = " << chrono::duration_cast<chrono::microseconds> (end - begin).count() << " microseconds" << endl;
}

void printResults(vector<int> array, int sortNumber, double bestCaseComparisons, double worstCaseComparisons, double comparisonCounter, double worstCaseSwaps, double bestCaseSwaps, double swapCounter)
{
	auto iterator = sortingNames.begin();
	for (int i = 1; i < sortNumber && iterator != sortingNames.end(); ++i)
		++iterator;
	if (iterator != sortingNames.end())
		cout << "* * * * *   " << iterator->second << "   * * * * *" << endl << endl;

	if (printArrays == true) {
		cout << "Array after sorting algorithm was called:" << endl;
		printArray(array);
	}

	printComparisonResults(bestCaseComparisons, worstCaseComparisons, comparisonCounter);
	if (sortNumber != 2)
		comparisonRates.insert({ sortNumber, (((abs(comparisonCounter - worstCaseComparisons)) / (worstCaseComparisons - bestCaseComparisons)) * 100)});
	printSwapResults(worstCaseSwaps, bestCaseSwaps, swapCounter);
	swapRates.insert({ sortNumber, (((abs(swapCounter - worstCaseSwaps)) / (worstCaseSwaps - bestCaseSwaps)) * 100) });
}

void printResultsNoSwap(vector<int> array, int sortNumber, double bestCaseComparisons, double worstCaseComparisons, double comparisonCounter) {
	auto iterator = sortingNames.begin();
	for (int i = 1; i < sortNumber && iterator != sortingNames.end(); ++i)
		++iterator;
	if (iterator != sortingNames.end())
		cout << "* * * * *   " << iterator->second << "   * * * * *" << endl << endl;
	
	if (printArrays == true) {
		cout << "Array after sorting algorithm was called:" << endl;
		printArray(array);
	}

	printComparisonResults(bestCaseComparisons, worstCaseComparisons, comparisonCounter);
	comparisonRates.insert({ sortNumber, (((abs(comparisonCounter - worstCaseComparisons)) / (worstCaseComparisons - bestCaseComparisons)) * 100) });
	cout << "This sorting algorithm does not operate via conducting swaps." << endl << endl;
	swapRates.insert({ 4,-10 });
}

void printSortedComparisonRates() {
	cout << "Algorithms Sorted By Most Efficient Comparison Rate" << endl << endl;
	
	vector<pair<int, double>> pairs;
	for (auto itr = comparisonRates.begin(); itr != comparisonRates.end(); ++itr) {
		pairs.push_back(*itr);
	}

	sort(pairs.begin(), pairs.end(), [=](pair<int, double>& a, pair<int, double>& b) {
		return a.second > b.second;
	}
	);

	double testValue = 1.0;

	for (int i = 0; i < pairs.size(); i++) {
		if (typeid(pairs[i].second) == typeid(testValue))
			cout << sortingNames[pairs[i].first] << ":\t" << pairs[i].second << "%" << endl;
	}
}

void printSortedSwapRates() {
	cout << "Algorithms Sorted By Most Efficient Swap Rate" << endl << endl;
	
	vector<pair<int, double>> pairs;
	for (auto itr = swapRates.begin(); itr != swapRates.end(); ++itr)
		pairs.push_back(*itr);

	sort(pairs.begin(), pairs.end(), [=](pair<int, double>& a, pair<int, double>& b) {
		return a.second > b.second;
	}
	);

	for (int i = 0; i < pairs.size(); i++) {
		if (i != 4)
			cout << sortingNames[pairs[i].first] << ":\t" << pairs[i].second << "%" << endl;
	}
}