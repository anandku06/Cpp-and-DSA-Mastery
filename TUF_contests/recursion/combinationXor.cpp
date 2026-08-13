// Combination XOR
// Medium

// Given an array of distinct integers nums and an integer k, return all unique non-empty combinations of elements with a bitwise XOR of k. Return an empty vector if no combinations are possible.

// Each element can be used only once in each combination. Two combinations are unique if at least one element is present in only one combination. Answer can be returned in any order.

// Example 1

// Input: nums = [57, 21, 8, 52, 41, 73], k = 57

// Output: [[8, 21, 41, 52, 57], [57]]

// Explanation:

// 8 xor 21 xor 41 xor 52 xor 57 = 57

// 57 itself is another combination.

// No other distinct combination exists.

// Example 2

// Input: nums = [1, 2, 3, 5], k = 1

// Output: [[1], [2, 3]]

// Explanation:

// 2 ^ 3 = 1

// 1 itself is another combination.

// No other distinct combination exists.

// Constraints

// 1 <= nums.length <= 10
// 0 <= nums[i] <= 1000
// 0 <= k <= 1000

// Approach: Backtracking
// Intuition
// We can use backtracking to generate all possible combinations of the elements in the array. For each combination, we can calculate the bitwise XOR of the elements and check if it is equal to k. If it is, we can add the combination to the result vector. We can use a set to store the unique combinations and avoid duplicates.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtrack(vector<int> &nums, int k, int start, int currentXor, vector<int> &combination, set<vector<int>> &uniqueCombinations)
    {
        if (currentXor == k && !combination.empty())
        {
            uniqueCombinations.insert(combination); // add the current combination to the set if the XOR is equal to k
        }

        for (int i = start; i < nums.size(); i++)
        {
            combination.push_back(nums[i]);                                                   // include the current element in the combination
            backtrack(nums, k, i + 1, currentXor ^ nums[i], combination, uniqueCombinations); // recurse with the next index and updated XOR
            combination.pop_back();                                                           // backtrack by removing the last element added
        }
    }

    vector<vector<int>> combinationXor(vector<int> &nums, int k)
    {
        vector<vector<int>> result;          // to store the final result
        vector<int> combination;             // to store the current combination
        set<vector<int>> uniqueCombinations; // to store unique combinations

        backtrack(nums, k, 0, 0, combination, uniqueCombinations); // call the backtracking function

        for (const auto &comb : uniqueCombinations)
        {
            result.push_back(comb); // add unique combinations to the result
        }

        return result; // return the final result
    }
};