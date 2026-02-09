// Find Kth Rotation
// Difficulty: Easy
// Accuracy: 23.16%
// Submissions: 335K+
// Points: 2
// Average Time: 20m

// Given an increasing sorted rotated array arr[] of distinct integers. The array is right-rotated k times. Find the value of k.
// Let's suppose we have an array arr[] = [2, 4, 6, 9], if we rotate it by 2 times it will look like this:
// After 1st Rotation : [9, 2, 4, 6]
// After 2nd Rotation : [6, 9, 2, 4]

// Examples:

// Input: arr[] = [5, 1, 2, 3, 4]
// Output: 1
// Explanation: The given array is [5, 1, 2, 3, 4]. The original sorted array is [1, 2, 3, 4, 5]. We can see that the array was rotated 1 times to the right.
// Input: arr = [1, 2, 3, 4, 5]
// Output: 0
// Explanation: The given array is not rotated.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 107

// approach : find the first minimum element its position will be the k rotations done

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthRotations(vector<int> &nums)
    {
        int n = nums.size();

        int res = 0;

        int mini = *min_element(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != mini)
                res++;
            else
                break;
        }

        return res;
    }
};