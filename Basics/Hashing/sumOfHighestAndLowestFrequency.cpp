// Sum of Highest and Lowest Frequency
// Easy

// Company
// Given an array of n integers, find the sum of the frequencies of the highest occurring number and lowest occurring number.

// Example 1

// Input: arr = [1, 2, 2, 3, 3, 3]

// Output: 4

// Explanation: The highest frequency is 3 (element 3), and the lowest frequency is 1 (element 1). Their sum is 3 + 1 = 4.

// Example 2

// Input: arr = [4, 4, 5, 5, 6]

// Output: 3

// Explanation: The highest frequency is 2 (elements 4 and 5), and the lowest frequency is 1 (element 6). Their sum is 2 + 1 = 3.

// Now your turn!

// Input: arr = [10, 9, 7, 7, 8, 8, 8]

// Output:

// Correct

// 4

// 5
// Constraints

// 1 <= n <= 105
// 1 <= arr[i] <= 104

// thought process:
// 1. we can use a hash map to count the frequency of each element in the array
// 2. we can then find the highest and lowest frequency and return their sum

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumOfHighestAndLowestFrequency(vector<int> &nums)
    {
        unordered_map<int, int> hash;
        int maxFreq = 0, minFreq = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            hash[nums[i]]++;
        }

        for (auto it : hash)
        {
            maxFreq = max(maxFreq, it.second);
            minFreq = min(minFreq, it.second);
        }

        return maxFreq + minFreq;
    }
};