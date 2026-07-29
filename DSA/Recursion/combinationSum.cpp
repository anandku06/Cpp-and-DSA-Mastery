// 39. Combination Sum
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.
// Example 2:

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]
// Example 3:

// Input: candidates = [2], target = 1
// Output: []

// Constraints:

// 1 <= candidates.length <= 30
// 2 <= candidates[i] <= 40
// All elements of candidates are distinct.
// 1 <= target <= 40

// approach: We can use a backtracking approach to generate all possible combinations of candidate numbers that sum up to the target. We will use a recursive function that takes the current combination, the remaining target, and the starting index as parameters. In each recursive call, we will iterate through the candidates starting from the given index, and for each candidate, we will check if it is greater than the remaining target. If it is, we can break the loop since all subsequent candidates will also be greater. If it is not, we will add the candidate to the current combination and recursively call the function with the updated combination and remaining target. After the recursive call, we will remove the last added candidate to backtrack and explore other combinations.

// The time complexity of this approach is O(2^n) in the worst case, where n is the number of candidates, since we may explore all possible combinations. The space complexity is O(k) where k is the maximum depth of the recursion, which can be at most n in the worst case.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &candidates, vector<int> &temp, int target, int index, vector<vector<int>> &result)
    {
        if (target == 0)
        { // base case: if the remaining target is 0, we have found a valid combination, so we add it to the result
            result.push_back(temp);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            if (candidates[i] > target)
                break; // if the current candidate is greater than the remaining target, we can break the loop since all subsequent candidates will also be greater

            temp.push_back(candidates[i]);                              // add the current candidate to the current combination
            solve(candidates, temp, target - candidates[i], i, result); // recursively call the function with the updated combination and remaining target
            temp.pop_back();                                            // remove the last added candidate to backtrack and explore other combinations
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;                 // to store the final result of combinations
        vector<int> temp;                           // to store the current combination
        solve(candidates, temp, target, 0, result); // call the recursive function to find all combinations
        return result;                              // return the final result
    }
};