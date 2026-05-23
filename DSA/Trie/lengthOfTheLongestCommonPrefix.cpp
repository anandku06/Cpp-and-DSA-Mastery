// 3043. Find the Length of the Longest Common Prefix
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given two arrays with positive integers arr1 and arr2.

// A prefix of a positive integer is an integer formed by one or more of its digits, starting from its leftmost digit. For example, 123 is a prefix of the integer 12345, while 234 is not.

// A common prefix of two integers a and b is an integer c, such that c is a prefix of both a and b. For example, 5655359 and 56554 have common prefixes 565 and 5655 while 1223 and 43456 do not have a common prefix.

// You need to find the length of the longest common prefix between all pairs of integers (x, y) such that x belongs to arr1 and y belongs to arr2.

// Return the length of the longest common prefix among all pairs. If no common prefix exists among them, return 0.

// Example 1:

// Input: arr1 = [1,10,100], arr2 = [1000]
// Output: 3
// Explanation: There are 3 pairs (arr1[i], arr2[j]):
// - The longest common prefix of (1, 1000) is 1.
// - The longest common prefix of (10, 1000) is 10.
// - The longest common prefix of (100, 1000) is 100.
// The longest common prefix is 100 with a length of 3.
// Example 2:

// Input: arr1 = [1,2,3], arr2 = [4,4,4]
// Output: 0
// Explanation: There exists no common prefix for any pair (arr1[i], arr2[j]), hence we return 0.
// Note that common prefixes between elements of the same array do not count.

// Constraints:

// 1 <= arr1.length, arr2.length <= 5 * 104
// 1 <= arr1[i], arr2[i] <= 108

// approach: take prefix from arr1 and check if it is a prefix of any element in arr2, and keep track of the longest prefix found so far, and return its length at the end. The time complexity of this approach is O(n * m * k) where n is the length of arr1, m is the length of arr2, and k is the average length of the integers in arr1 and arr2.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_set<int> prefixes; // To store the prefixes of elements in arr1

        for (int v : arr1)
        {
            // until we have not seen the prefix before and the prefix is greater than 0, we keep inserting the prefix into the set and removing the last digit to get the next prefix
            while (!prefixes.count(v) && v > 0)
            {
                prefixes.insert(v); // Insert the current prefix into the set
                v /= 10;            // Remove the last digit to get the next prefix
            }
        }

        int result = 0; // To store the length of the longest common prefix found so far

        for (int v : arr2)
        {
            // find the longest prefix of v that is present in the set of prefixes, and update the result if the length of this prefix is greater than the current result
            while (!prefixes.count(v) && v > 0)
            {
                v /= 10; // Remove the last digit to get the next prefix
            }

            if (v > 0)                                   // If we found a common prefix, update the result with the length of this prefix
                result = max(result, (int)log10(v) + 1); // The length of the prefix is equal to the number of digits in it, which can be calculated using log10(v) + 1
        }

        return result; // Return the length of the longest common prefix found
    }
};

// using Trie

struct TrieNode
{
    bool isEndOfNum; // To indicate if a number ends at this node
    TrieNode *children[10]; // Since we are dealing with digits, we can have at most 10 children for each node

    TrieNode() : isEndOfNum(false)
    {
        for (int i = 0; i < 10; i++)
            children[i] = nullptr; // Initialize all children to nullptr
    }
};

class Solution2
{
public:
    void insert(int num, TrieNode *root)
    {
        TrieNode *node = root;          // Start from the root node
        string numStr = to_string(num); // Convert the number to a string to easily access its digits

        for (char c : numStr)
        {
            int digit = c - '0'; // Get the integer value of the digit
            if (!node->children[digit])
                node->children[digit] = new TrieNode(); // Create a new node if it doesn't exist
            node = node->children[digit];               // Move to the child node corresponding to the current digit
        }
        node->isEndOfNum = true; // Mark the end of the number
    }

    int search(int num, TrieNode *root)
    {
        TrieNode *node = root;          // Start from the root node
        string numStr = to_string(num); // Convert the number to a string to easily access its digits
        int prefixLength = 0;           // To keep track of the length of the common prefix found so far

        for (char c : numStr)
        {
            int digit = c - '0'; // Get the integer value of the digit
            if (!node->children[digit])
                break;                    // If there is no child node for the current digit, we have found the longest common prefix, so we break out of the loop
            node = node->children[digit]; // Move to the child node corresponding to the current digit
            prefixLength++;               // Increment the prefix length for each matching digit
        }

        return prefixLength; // Return the length of the longest common prefix found for this number
    }

    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        TrieNode *root = new TrieNode(); // Create the root of the trie

        // Insert all numbers from arr1 into the trie
        for (int num : arr1)
        {
            insert(num, root);
        }

        int result = 0; // To store the length of the longest common prefix found so far
        // Search for the longest common prefix for each number in arr2
        for (int num : arr2)
        {
            result = max(result, search(num, root)); // Update the result with the length of the longest common prefix found for the current number
        }

        return result; // Return the length of the longest common prefix found
    }
};