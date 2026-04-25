// 49. Group Anagrams
// Medium
// Topics
// premium lock icon
// Companies
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]

// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Explanation:

// There is no string in strs that can be rearranged to form "bat".
// The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
// The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
// Example 2:

// Input: strs = [""]

// Output: [[""]]

// Example 3:

// Input: strs = ["a"]

// Output: [["a"]]

// Constraints:

// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters.

// brute force approach
// We can sort each string in the array and use the sorted string as a key in a hash map. The value of the hash map will be a list of strings that are anagrams of each other. After processing all the strings, we can return the values of the hash map as the result. The time complexity of this approach is O(n * k log k) where n is the number of strings and k is the maximum length of a string.

// optimal approach
// We can use a hash map to count the frequency of each character in the string. We can represent the frequency count as a tuple or a string and use it as a key in the hash map. The value of the hash map will be a list of strings that are anagrams of each other. After processing all the strings, we can return the values of the hash map as the result. The time complexity of this approach is O(n * k) where n is the number of strings and k is the maximum length of a string.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagramsBrute(vector<string> &strs)
    {
        unordered_map<string, vector<string>> hash;

        for (string i : strs)
        {
            string sortedStr = i;
            sort(sortedStr.begin(), sortedStr.end());
            hash[sortedStr].push_back(i);
        }
        vector<vector<string>> result;
        for (auto &pair : hash)
        {
            result.push_back(pair.second);
        }
        return result;
    }

    vector<vector<string>> groupAnagramsOptimal(vector<string> &strs)
    {
        unordered_map<string, vector<string>> hash;

        for (string i : strs)
        {
            vector<int> charCount(26, 0);
            for (char c : i)
            {
                charCount[c - 'a']++;
            }
            string key;
            // using the frequency count as a key in the hash map
            for (int count : charCount)
            {
                key += to_string(count) + '#'; // using '#' as a separator
            }
            hash[key].push_back(i); // adding the original string to the list of anagrams corresponding to the key
        }
        vector<vector<string>> result;
        for (auto &pair : hash)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};