#pragma once
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>

using namespace std;

int partition(vector<int>& array, int start, int end, double& swapCounter, double& comparisonCounter);
void quickSort(vector<int>& array, int s, int f, double& swapCounter, double& comparisonCounter);
void quickSortContainer(vector<int> array);

#endif