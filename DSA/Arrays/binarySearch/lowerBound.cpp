// Lower Bound
// Easy

// Hints
// Company
// Given a sorted array of nums and an integer x, write a program to find the lower bound of x.

// The lower bound algorithm finds the first and smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.

// If no such index is found, return the size of the array.

// Example 1

// Input : nums= [1,2,2,3], x = 2

// Output:1

// Explanation:

// Index 1 is the smallest index such that arr[1] >= x.

// Example 2

// Input : nums= [3,5,8,15,19], x = 9

// Output: 3

// Explanation:

// Index 3 is the smallest index such that arr[3] >= x.

// Constraints

//   1 <= nums.length <= 105
//   -105 < nums[i], x < 105
//   nums is sorted in ascending order.

// Approach: Using Binary Search
// Intuition
// We can use binary search to find the lower bound of x in the sorted array. We will initialize two pointers, left and right, to the start and end of the array, respectively. We will calculate the mid index and compare the element at mid with x. If the element at mid is greater than or equal to x, we will move the right pointer to mid; otherwise, we will move the left pointer to mid + 1. We will continue this process until left is less than right, at which point left will be the index of the lower bound of x in the array. If left is equal to the size of the array, it means that there is no element in the array that is greater than or equal to x, so we will return left.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lowerBound(vector<int> &nums, int x)
    {
        int n = nums.size();

        int left = 0, right = n - 1;
        int ans = n; // initialize ans to n, which is the size of the array

        while (left <= right)
        {
            int mid = left + (right - left) / 2; // calculate the mid index

            if (nums[mid] >= x)
            {                    // if the element at mid is greater than or equal to x
                ans = mid;       // update ans to mid, as it is a potential lower bound
                right = mid - 1; // move the right pointer to mid - 1 to find a smaller index that is greater than or equal to x
            }
            else
                left = mid + 1; // otherwise, move the left pointer to mid + 1 to find an index that is greater than or equal to x
        }
        return ans; // ans will be the index of the lower bound of x in the array, or n if there is no such index
    }
};