# Sorting-Algorithm-Analyzer-Tool
             ---------------------------------------------------------------------------------------------------
             |   _____            _   _                        _                  _ _   _                      |
             |  / ____|          | | (_)                 /\   | |                (_) | | |                     |
             | | (___   ___  _ __| |_ _ _ __   __ _     /  \  | | __ _  ___  _ __ _| |_| |__  _ __ ___   ___   |
             |  \___ \ / _ \| '__| __| | '_ \ / _` |   / /\ \ | |/ _` |/ _ \| '__| | __| '_ \| '_ ` _ \ / __|  |
             |  ____) | (_) | |  | |_| | | | | (_| |  / ____ \| | (_| | (_) | |  | | |_| | | | | | | | |\__ \  |
             | |_____/ \___/|_|   \__|_|_| |_|\__, | /_/    \_\_|\__, |\___/|_|  |_|\__|_| |_|_| |_| |_||___/  |
             |                                 __/ |              __/ |                                        |
             |                                |___/              |___/                                         |
             ---------------------------------------------------------------------------------------------------
                                   A comparison, swap, and runtime analyzer tool designed by:
                                            Joseph Re  (josephfrancisre@gmail.com)

This repository contains C++ code for an analyzer tool.

The custom built tool evaluates 5 major sorting algorithms based on runtime speed, comparison usage, and swap executions for dynamic input parameters set by the user.

Please note that the sorting algorithms as they are implemented use vectors (not lists). Vectors story values in contiguous memory locations to make a syncronized access method for all values. Whether lists or vectors are used has a negligable difference on the results of the tool.

-----------------------------------------------------------------------------------------------------------------------------------------------------------

<b>Sorting algorithms utilized:</b><br><br>
<b>1. Insertion Sort</b><br>
(Insertion sort builds the final sorted list one item at a time by placing the element in the correct position at every comparison)<br><br>
<b>2. Selection Sort</b>
<br>(Selection sort selects the smallest element from an unsorted list in each iteration and places that element at the beginning of the unsorted list)<br><br>
<b>3. Bubble Sort</b><br>
(Bubble Sort repeatidly compares two adjacent elements and swaps them until all values are in the intended order of the resulting list)<br><br>
<b>4. Merge Sort</b><br>
(Merge Sort divides the sorting procedure into many subproblems that are solved individually at the time of recursive stack unwinding)<br><br>
<b>5. Quick Sort</b><br>
(Quick Sort repeatedly biforcates the list into sublists by comparing the values to a random pivot element until the base case of the sublist having only 1 element in it)

-----------------------------------------------------------------------------------------------------------------------------------------------------------

<b>Efficiency measures utilized:</b><br><br>
<b>1. Runtime Speed</b><br>
(Measured in microseconds)<br><br>
<b>2. Comparison Rate</b><br>
(Percentage of comparisons not needed to be made versus the worst cast scenario for a given algorithm)<br><br>
<b>3. Swap Rate</b><br>
(Percentage of swaps not needed to be made versus the worst cast scenario for a given algorithm)
