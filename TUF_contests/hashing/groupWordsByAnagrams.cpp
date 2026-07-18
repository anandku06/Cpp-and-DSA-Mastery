// Group Words by Anagrams
// Medium

// Given an array of strings strs, group the words that are anagrams of each other.

// An anagram is a word formed by rearranging the letters of another word using all the original letters exactly once. You may return the groups in any order.

// Example 1

// Input: strs = ["race", "care", "acre", "bake", "beak", "keep"]

// Output: [["race", "care", "acre"], ["bake", "beak"], ["keep"]]

// Explanation:

// "race", "care", and "acre" are anagrams and can be rearranged to form each other.

// "bake" and "beak" are anagrams and form another group.

// "keep" does not have any anagrams in the list and forms its own group.

// Example 2

// Input: strs = ["bob", "obb", "boo", "oob", "bbo"]

// Output: [["bob", "obb", "bbo"], ["boo", "oob"]]

// Explanation:

// "bob", "obb", and "bbo" are anagrams and can be rearranged to form each other.

// "boo" and "oob" are anagrams and form another group.

// Constraints

// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100

// Approach: Using a hash map to group the words by their sorted character representation. The time complexity of this approach is O(n * k log k) where n is the number of words and k is the maximum length of a word.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> anagramGroups; // create a hash map to store the groups of anagrams

        for (const string &word : strs)
        {
            string sortedWord = word;                   // create a copy of the word to sort
            sort(sortedWord.begin(), sortedWord.end()); // sort the characters of the word

            anagramGroups[sortedWord].push_back(word); // add the original word to the corresponding group in the hash map
        }

        vector<vector<string>> result; // create a vector to store the final result

        for (auto &group : anagramGroups)
        {
            result.push_back(move(group.second)); // move each group of anagrams into the result vector
        }

        return result; // return the grouped anagrams
    }
};