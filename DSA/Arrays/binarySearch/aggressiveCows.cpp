// Aggressive Cows
// Difficulty: MediumAccuracy: 59.57%Submissions: 233K+Points: 4Average Time: 30m
// Given an integer array arr[], which denotes the positions of stalls. All the positions are distinct. There are k aggressive cows.

// Assign the cows to the stalls such that the minimum distance between any two cows is maximized.

// Examples:

// Input: arr[] = [1, 2, 4, 8, 9], k = 3
// Output: 3
// Explanation: The first cow can be placed at arr[0], the second at arr[2], and the third at arr[3]. The minimum distance between any two cows is 3 (between arr[0] and arr[2]), which is the maximum possible among all valid arrangements.
// Input: arr[] = [10, 1, 2, 7, 5], k = 3
// Output: 4
// Explanation: The first cow can be placed at arr[0], the second at arr[1], and the third at arr[4]. In this arrangement, the minimum distance between any two cows is 4 (between arr[1] and arr[4]), which is the maximum possible among all valid arrangements.
// Constraints:
// 2 ≤ arr.size() ≤ 106
// 0 ≤ arr[i] ≤ 108
// 2 ≤ k ≤ arr.size()

// Approach: Binary Search
// Intuition
// The problem can be solved using a binary search approach. We can define a function that checks if it is possible to place the cows in the stalls such that the minimum distance between any two cows is at least a given value. We can then use binary search to find the maximum possible minimum distance.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPlaceCows(vector<int> &arr, int k, int minDist)
    {
        int count = 1;        // Place the first cow in the first stall
        int lastPos = arr[0]; // Position of the last placed cow

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - lastPos >= minDist) // Check if the current stall is at least 'minDist' away from the last placed cow
            {
                count++;          // Place a cow in this stall
                lastPos = arr[i]; // Update the position of the last placed cow
            }

            if (count == k) // If all cows have been placed, return true
                return true;
        }

        return false; // If not all cows could be placed, return false
    }

    int aggressiveCows(vector<int> &arr, int k)
    {
        // sorting bcz we need to place cows in the stalls such that the minimum distance between any two cows is maximized. By sorting the stall positions, we can easily check the distances between adjacent stalls and ensure that we are placing the cows in a way that maximizes the minimum distance. Sorting allows us to efficiently determine the feasibility of placing cows at specific distances using a binary search approach.
        sort(arr.begin(), arr.end()); // Sort the array of stall positions

        int left = 1;                         // Minimum possible distance
        int right = arr.back() - arr.front(); // Maximum possible distance
        int result = 0;                       // Variable to store the maximum minimum distance

        // left <= right is used to ensure that we continue searching until the search space is exhausted. This condition allows us to explore all possible distances between the minimum and maximum distances, ensuring that we find the optimal solution for placing the cows in the stalls.
        while (left <= right)
        {
            int mid = left + (right - left) / 2; // Calculate the middle distance

            if (canPlaceCows(arr, k, mid))
            {
                result = mid;   // Update result if cows can be placed with at least 'mid' distance
                left = mid + 1; // Try for a larger distance
            }
            else
            {
                right = mid - 1; // Try for a smaller distance
            }
        }

        return result; // Return the maximum minimum distance found
    }
};