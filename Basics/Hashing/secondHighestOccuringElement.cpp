// Second Highest Occurring Element
// Easy

// Company
// Given an array of n integers, find the second most frequent element in it.

// If there are multiple elements that appear second most frequent times, find the smallest of them.

// If second most frequent element does not exist return -1.

// Example 1

// Input: arr = [1, 2, 2, 3, 3, 3]

// Output: 2

// Explanation:

// The number 2 appears the second most (2 times) and number 3 appears the most(3 times).

// Example 2

// Input: arr = [4, 4, 5, 5, 6, 7]

// Output: 6

// Explanation:

// Both 6 and 7 appear second most times, but 6 is smaller.

// Now your turn!

// Input: arr = [10, 9 ,7, 7]

// Output:

// Correct

// 9

// 10
// Constraints

// 1 <= n <= 105
// 1 <= arr[i] <= 104

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int secondMostFrequentElement(vector<int> &nums)
    {
        unordered_map<int, int> hash;
        int maxFreq = 0, secFreq = 0;
        int maxEle = -1, secEle = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            hash[nums[i]]++;
        }

        for (auto it : hash)
        {
            int ele = it.first;
            int freq = it.second;

            if (freq > maxFreq)
            {
                secFreq = maxFreq;
                maxFreq = freq;
                secEle = maxEle;
                maxEle = ele;
            }

            else if (freq == maxFreq)
            {
                maxEle = min(maxEle, ele);
            }

            else if (freq > secFreq)
            {
                secFreq = freq;
                secEle = ele;
            }

            else if (freq == secFreq)
            {
                secEle = min(secEle, ele);
            }
        }

        return secEle;
    }
};