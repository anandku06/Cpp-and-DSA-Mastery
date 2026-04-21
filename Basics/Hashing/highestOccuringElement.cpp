// Highest Occurring Element in an Array
// Easy

// Company
// Given an array nums of n integers, find the most frequent element in it i.e., the element that occurs the maximum number of times. If there are multiple elements that appear a maximum number of times, find the smallest of them.

// Please note that this section might seem a bit difficult without prior knowledge on what hashing is, we will soon try to add basics concepts for your ease! If you know the concepts already please go ahead to give a shot to the problem. Cheers!

// Example 1

// Input: nums = [1, 2, 2, 3, 3, 3]

// Output: 3

// Explanation: The number 3 appears the most (3 times). It is the most frequent element.

// Example 2

// Input: nums = [4, 4, 5, 5, 6]

// Output: 4

// Explanation: Both 4 and 5 appear twice, but 4 is smaller. So, 4 is the most frequent element.

// Example 3

// Input: nums = [2, 4, 3, 2, 5, 4]

// Output:

// 2
// Constraints

// 1 <= n <= 105
// 1 <= nums[i] <= 104

// thought process: We can use a hash map to count the frequency of each element in the array. Then, we can iterate through the hash map to find the element with the highest frequency. If there are multiple elements with the same frequency, we can keep track of the smallest one.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int highestOccurenceElement(vector<int> &nums)
    {
        // Create a hash map to count the frequency of each element
        unordered_map<int, int> frequencyMap;

        // take vars to keep track of the maximum frequency and the most frequent element
        int maxFrequency = 0;
        int mostFrequentElement = -1;

        // Count the frequency of each element in the array
        for (size_t i = 0; i < nums.size(); i++)
            frequencyMap[nums[i]]++;

        // Iterate through the hash map to find the most frequent element
        for (auto it : frequencyMap)
        {
            // If the current element's frequency is greater than the max frequency, update the max frequency and the most frequent element
            if (it.second > maxFrequency)
            {
                maxFrequency = it.second;
                mostFrequentElement = it.first;
            }
            // If the current element's frequency is equal to the max frequency, check if it's smaller than the current most frequent element
            else if (it.second == maxFrequency)
            {
                mostFrequentElement = min(mostFrequentElement, it.first);
            }
        }

        return mostFrequentElement;
    }
};