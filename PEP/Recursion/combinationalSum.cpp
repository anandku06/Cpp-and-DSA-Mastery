// 39. Combination Sum
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

// approach: We can use a recursive approach to generate all possible combinations of candidates that sum up to the target. We can start with an empty combination and keep adding candidates to it until we reach the target. If we exceed the target, we backtrack and try a different combination. We can also use a loop to iterate through the candidates and avoid generating duplicate combinations.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> result; // to store the final result

    void solve(vector<int> &candidates, vector<int> &temp, int target, int i)
    {
        if (target == 0)
        {                           // base case: if the target is 0, we have found a valid combination
            result.push_back(temp); // add the current combination to the result
            return;
        }

        if (i == candidates.size() || target < 0)
        { // base case: if we have reached the end of the candidates array or if the target is negative, we cannot find a valid combination
            return;
        }

        temp.push_back(candidates[i]);                      // picking the current candidate and moving to the next candidate
        solve(candidates, temp, target - candidates[i], i); // after picking the current candidate, we need to backtrack and remove it from the temp array before moving to the next candidate. This way, we can explore other combinations without the current candidate.
        temp.pop_back();                                    // backtracking step, removing the last element from the temp array to explore other combinations without the current candidate. This is necessary to ensure that we can explore all possible combinations, including those that do not include the current candidate, and to prevent generating duplicate combinations.
        solve(candidates, temp, target, i + 1);             // not-picking the current candidate and moving to the next candidate
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> temp;                   // to store the current combination
        solve(candidates, temp, target, 0); // calling the recursive function to generate all combinations starting from index 0
        return result;
    }
};