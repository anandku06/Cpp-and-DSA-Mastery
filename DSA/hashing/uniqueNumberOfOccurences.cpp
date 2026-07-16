// 1207. Unique Number of Occurrences
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

// Example 1:

// Input: arr = [1,2,2,1,1,3]
// Output: true
// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
// Example 2:

// Input: arr = [1,2]
// Output: false
// Example 3:

// Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
// Output: true

// Constraints:

// 1 <= arr.length <= 1000
// -1000 <= arr[i] <= 1000

// approach: we can use a hash map to count the occurrences of each value in the array. Then we can use a set to check if the number of occurrences is unique. If the size of the set is equal to the size of the hash map, then the number of occurrences is unique.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        // Step 1: Count how many times each number appears
        unordered_map<int, int> counts;
        for (int num : arr)
        {
            counts[num]++;
        }

        // Step 2: Check if any two numbers have the same count
        unordered_set<int> uniqueCounts;
        for (auto &pair : counts)
        {
            int frequency = pair.second;

            // If we've already seen this exact frequency, it's not unique!
            if (uniqueCounts.find(frequency) != uniqueCounts.end())
            {
                return false;
            }
            uniqueCounts.insert(frequency);
        }

        return true;
    }
};