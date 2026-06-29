// Bubble Sort
// Difficulty: EasyAccuracy: 59.33%Submissions: 360K+Points: 2Average Time: 15m
// Given an array, arr[]. Sort the array using bubble sort algorithm.

// Examples :

// Input: arr[] = [4, 1, 3, 9, 7]
// Output: [1, 3, 4, 7, 9]
// Explanation: After Sorting the array in ascending order of their values is [1, 3, 4, 7, 9].
// Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
// Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// Explanation: Sort the array in ascending order of their values.
// Input: arr[] = [1, 2, 3, 4, 5]
// Output: [1, 2, 3, 4, 5]
// Explanation: An array that is already sorted should remain unchanged after applying bubble sort.
// Constraints:
// 1 ≤ arr.size() ≤ 103
// 1 ≤ arr[i] ≤ 103

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void static bubbleSort(vector<int> &arr)
    {
        int n = arr.size();

        // Outer loop: Controls the number of passes through the array.
        // After each pass 'i', the largest 'i' elements are guaranteed to be in their correct final positions at the end.
        for (int i = 0; i < n; i++)
        {

            // Optimization flag: Keeps track of whether any elements were swapped during this pass.
            // If no swaps happen, the array is already sorted, and we can stop early.
            bool didSwap = false;

            // Inner loop: Performs adjacent comparisons.
            // We stop at 'n - i - 1' because the last 'i' elements are already sorted.
            // Using '<' prevents 'j + 1' from going out of bounds (max index accessed is n - 1).
            for (int j = 0; j < n - i - 1; j++)
            {

                // If the current element is greater than the next element, swap them.
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    didSwap = true; // Mark that a swap occurred
                }
            }

            // If no elements were swapped during the entire pass, the array is sorted.
            // Break early to achieve O(n) best-case time complexity.
            if (!didSwap)
            {
                break;
            }
        }
    }
};