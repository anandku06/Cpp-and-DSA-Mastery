// Second Largest Element
// Easy

// Hints
// Company
// Given an array of integers nums, return the second-largest element in the array. If the second-largest element does not exist, return -1.

// Example 1

// Input: nums = [8, 8, 7, 6, 5]

// Output: 7

// Explanation:

// The largest value in nums is 8, the second largest is 7

// Example 2

// Input: nums = [10, 10, 10, 10, 10]

// Output: -1

// Explanation:

// The only value in nums is 10, so there is no second largest value, thus -1 is returned

// Example 3

// Input: nums = [7, 7, 2, 2, 10, 10, 10]

// Output:

// 7
// Constraints

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// nums may contain duplicate elements.

// approach :
// In a single traversal of the sorted array, we'll update both variables, largest and second largest
// if the current element is larger than the largest, secondlarge = large and large = nums[i];

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int secondLargest(vector<int> &nums)
    {
        int n = nums.size();

        if(n < 2) return -1; // check if array isn't less than 2 elements

        int largest = INT_MIN, secLargest = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > largest)
            {
                secLargest = largest;
                largest = nums[i];
            }
            else if (nums[i] > secLargest && nums[i] != largest)
            {
                secLargest = nums[i];
            }
        }

        return secLargest == INT_MIN ? -1 : secLargest;
    }
};