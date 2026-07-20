// K-th element of two Arrays
// Difficulty: MediumAccuracy: 37.4%Submissions: 415K+Points: 4Average Time: 15m
// Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.

// Examples :

// Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 5
// Output: 6
// Explanation: The final combined sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.
// Input: a[] = [1, 4, 8, 10, 12], b[] = [5, 7, 11, 15, 17], k = 6
// Output: 10
// Explanation: Combined sorted array is [1, 4, 5, 7, 8, 10, 11, 12, 15, 17]. The 6th element of this array is 10.
// Constraints:
// 1 ≤ a.size(), b.size() ≤ 106
// 1 ≤ k ≤ a.size() + b.size()
// 0 ≤ a[i], b[i] ≤ 108

// Approach: Using Binary Search
// Intuition
// We can use a binary search approach to find the k-th element in the combined sorted array. The idea is to partition both arrays such that the left partition contains the first k elements of the combined sorted array. We will use binary search on the smaller array to find the correct partition point. The k-th element will be the maximum of the last elements of the left partitions of both arrays.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthElement(vector<int> &a, vector<int> &b, int k)
    {
        int n = a.size();
        int m = b.size();

        // Ensure that a is the smaller array
        if (n > m)
            return kthElement(b, a, k);

        int low = max(0, k - m); // The minimum number of elements we can take from a
        int high = min(k, n);    // The maximum number of elements we can take from a

        while (low <= high)
        {
            int mid1 = low + (high - low) / 2; // Number of elements taken from a
            int mid2 = k - mid1;               // Number of elements taken from b

            int leftA = (mid1 == 0) ? INT_MIN : a[mid1 - 1]; // Last element in the left partition of a
            int leftB = (mid2 == 0) ? INT_MIN : b[mid2 - 1]; // Last element in the left partition of b

            int rightA = (mid1 == n) ? INT_MAX : a[mid1]; // First element in the right partition of a
            int rightB = (mid2 == m) ? INT_MAX : b[mid2]; // First element in the right partition of b

            if (leftA <= rightB && leftB <= rightA)
            {
                // We have found the correct partition
                return max(leftA, leftB); // The k-th element is the maximum of the last elements of the left partitions
            }
            else if (leftA > rightB)
            {
                // We need to move towards the left in a
                high = mid1 - 1;
            }
            else
            {
                // We need to move towards the right in a
                low = mid1 + 1;
            }
        }

        return -1; // This line should never be reached if the input is valid
    }
};