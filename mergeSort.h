#pragma once
#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>

using namespace std;

void merge(vector<int>& array, int s, int q, int f, double& comparisonCounter);
void mergeSort(vector<int>& array, int s, int f, double& comparisonCounter);
void mergeSortContainer(vector<int> array);

#endif