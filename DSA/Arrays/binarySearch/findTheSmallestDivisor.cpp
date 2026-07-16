// 1283. Find the Smallest Divisor Given a Threshold
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

// Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

// The test cases are generated so that there will be an answer.

// Example 1:

// Input: nums = [1,2,5,9], threshold = 6
// Output: 5
// Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1.
// If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2).
// Example 2:

// Input: nums = [44,22,33,11,1], threshold = 5
// Output: 44

// Constraints:

// 1 <= nums.length <= 5 * 104
// 1 <= nums[i] <= 106
// nums.length <= threshold <= 106

// approach: binary search
// Intuition: The smallest divisor will be between 1 and the maximum element in the array. We can use binary search to find the smallest divisor that satisfies the condition.
// why max element: Because if we choose a divisor greater than the maximum element, the sum will be equal to the length of the array, which is less than or equal to the threshold. So we can ignore all divisors greater than the maximum element.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidDivisor(vector<int> &nums, int divisor, int threshold)
    {
        long long sum = 0; // use long long to avoid overflow
        for (int num : nums)
        {
            sum += (num + divisor - 1) / divisor; // equivalent to ceil(num / divisor)
        }
        return sum <= threshold; // check if the sum is less than or equal to threshold
    }

    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int left = 1;                                       // minimum possible divisor
        int right = *max_element(nums.begin(), nums.end()); // maximum possible divisor

        // l < r bcz we want to find the smallest divisor, so we will keep narrowing down the range until left == right, which will be our answer.
        while (left < right)
        {
            int mid = left + (right - left) / 2; // calculate the middle divisor
            if (isValidDivisor(nums, mid, threshold))
            {
                right = mid; // if valid, try to find a smaller divisor
            }
            else
            {
                left = mid + 1; // if not valid, try a larger divisor
            }
        }
        return left; // the smallest valid divisor
    }
};