#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <chrono>
#include "insertionSort.h"
#include "bubbleSort.h"
#include "selectionSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "printFunctions.h"

using namespace std;

extern map<int, double> comparisonRates;
extern map<int, double> swapRates;

bool printArrays;
map<int, string> sortingNames;

int main() {
	srand(time(0));
	int n, min, max;
	char res;

	sortingNames = {
		{1, "Insertion Sort"},
		{2, "Selection Sort"},
		{3, "Bubble Sort"},
		{4, "Merge Sort"},
		{5, "Quick Sort"}
	};

	cout << "     ---------------------------------------------------------------------------------------------------" << endl;
	cout << "     |   _____            _   _                        _                  _ _   _                      |" << endl;
	cout << "     |  / ____|          | | (_)                 /\\   | |                (_) | | |                     |" << endl;
	cout << "     | | (___   ___  _ __| |_ _ _ __   __ _     /  \\  | | __ _  ___  _ __ _| |_| |__  _ __ ___    ___  |" << endl;
	cout << "     |  \\___ \\ / _ \\| '__| __| | '_ \\ / _` |   / /\\ \\ | |/ _` |/ _ \\| '__| | __| '_ \\| '_ ` _ \\  / __| |" << endl;
	cout << "     |  ____) | (_) | |  | |_| | | | | (_| |  / ____ \\| | (_| | (_) | |  | | |_| | | | | | | | | \\__ \\ |" << endl;
	cout << "     | |_____/ \\___/|_|   \\__|_|_| |_|\\__, | /_/    \\_\\_|\\__, |\\___/|_|  |_|\\__|_| |_|_| |_| |_| |___/ |" << endl;
	cout << "     |                                 __/ |              __/ |                                        |" << endl;
	cout << "     |                                |___/              |___/                                         |" << endl;
	cout << "     ---------------------------------------------------------------------------------------------------" << endl;
	cout << "                           A comparison, swap, and runtime analyzer tool designed by:                   " << endl;
	cout << "                                    Joseph Re  (josephfrancisre@gmail.com)                              " << endl << endl;

	cout << "Please enter an n value: ";
	do {
		cin >> n;
	} while (n <= 0);

	cout << "Would you like to print out the arrays (Y/N)?: ";
	do {
		cin >> res;
	} while (res != 'y' && res != 'Y' && res != 'n' && res != 'N');

	if (res == 'y' || res == 'Y') {
		printArrays = true;
	}
	else {
		printArrays = false;
	}

	cout << "Please enter an minimum value for the range of numbers: ";
	do {
		cin >> min;
	} while (min <= 0);

	cout << "Please enter an maximum value for the range of numbers: ";
	do {
		cin >> max;
	} while (max <= 0 || (max < min));

	vector<int> array;

	for (int i = 0; i < n; i++) {
		array.push_back(((rand() % (max-min+1)) + min));
	}
	
	if (printArrays == true) {
		cout << endl;
		printDivider();
		printPreSortedArray(array);
	}
	printDivider();

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

	vector<TimeTuple> elapsedTimes;
	string name;

	for (int i = 1; i <= sortingNames.size(); i++) {
		chrono::steady_clock::time_point begin = chrono::steady_clock::now();
		switch (i) {
		case 1:
			insertionSort(array);
			name = "Insertion Sort";
			break;
		case 2:
			selectionSort(array);
			name = "Selection Sort";
			break;
		case 3:
			bubbleSort(array);
			name = "Bubble Sort";
			break;
		case 4:
			mergeSortContainer(array);
			name = "Merge Sort";
			break;
		case 5:
			quickSortContainer(array);
			name = "Quick Sort";
			break;
		};
		chrono::steady_clock::time_point end = chrono::steady_clock::now();
		
		TimeTuple tempTimeTuple = TimeTuple(name, begin, end);

		elapsedTimes.push_back(tempTimeTuple);

		printTimeElapsed(begin, end);
		printDivider();
	}

	cout << "Fastest Algorithms to Slowest for Provided Input" << endl << endl;

	for (int i = 0; i < 5; i++) {
		for (int j = i; j >= 1; j--) {
			if ((elapsedTimes[j].timeTupleEnd - elapsedTimes[j].timeTupleBegin).count() < (elapsedTimes[j - 1].timeTupleEnd - elapsedTimes[j - 1].timeTupleBegin).count()) {
				TimeTuple temp = elapsedTimes[j - 1];
				elapsedTimes[j - 1] = elapsedTimes[j];
				elapsedTimes[j] = temp;
			}
			else {
				break;
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		cout << (i + 1) << ". " << elapsedTimes[i].timeTupleName << " took " << chrono::duration_cast<chrono::microseconds>(elapsedTimes[i].timeTupleEnd - elapsedTimes[i].timeTupleBegin).count() << " microseconds." << endl;
	}

	printDivider();

	printSortedComparisonRates();

	printDivider();

	printSortedSwapRates();

	return 0;
}