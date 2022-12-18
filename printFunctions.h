#pragma once
#ifndef PRINTFUNCTIONS_H
#define PRINTFUNCTIONS_H

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <chrono>

using namespace std;

void printPreSortedArray(vector<int> array);
void printArray(vector<int> array);
void printComparisonResults(double bestCaseComparisons, double worstCaseComparisons, double comparisonCounter);
void printSwapResults(double worstCaseSwaps, double bestCaseSwaps, double swapCounter);
void printDivider();
void printTimeElapsed(chrono::steady_clock::time_point begin, chrono::steady_clock::time_point end);
void printResults(vector<int> array, int sortNumber, double bestCaseComparisons, double worstCaseComparisons, double comparisonCounter, double worstCaseSwaps, double bestCaseSwaps, double swapCounter);
void printResultsNoSwap(vector<int> array, int sortNumber, double bestCaseComparisons, double worstCaseComparisons, double comparisonCounter);
void printSortedComparisonRates();
void printSortedSwapRates();

#endif