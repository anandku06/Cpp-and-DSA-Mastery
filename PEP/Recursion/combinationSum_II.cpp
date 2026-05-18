// 40. Combination Sum II
// Medium
// Topics
// premium lock icon
// Companies
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output:
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output:
// [
// [1,2,2],
// [5]
// ]

// Constraints:

// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30

// approach: We can use a backtracking approach to generate all possible combinations of candidate numbers that sum up to the target. We will sort the candidates array to handle duplicates easily. We will use a recursive function that takes the current combination, the remaining target, and the starting index as parameters. In each recursive call, we will iterate through the candidates starting from the given index, and for each candidate, we will check if it is greater than the remaining target. If it is, we can break the loop since all subsequent candidates will also be greater. If it is not, we will add the candidate to the current combination and recursively call the function with the updated combination and remaining target. After the recursive call, we will remove the last added candidate to backtrack and explore other combinations. We will also skip duplicate candidates to avoid generating duplicate combinations.
// The time complexity of this approach is O(2^n) in the worst case, where n is the number of candidates, since we may explore all possible combinations. The space complexity is O(k) where k is the maximum depth of the recursion, which can be at most n in the worst case.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> result; // to store the final result of combinations

    void solve(vector<int> &candidates, vector<int> &temp, int target, int index)
    {
        if (target == 0)
        { // base case: if the remaining target is 0, we have found a valid combination, so we add it to the result
            result.push_back(temp);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
                continue; // skip duplicate candidates

            if (candidates[i] > target)
                break; // if the candidate is greater than the remaining target, we can break the loop since all subsequent candidates will also be greater

            temp.push_back(candidates[i]);                          // add the current candidate to the combination
            solve(candidates, temp, target - candidates[i], i + 1); // recursively call the function with the updated combination and remaining target
            temp.pop_back();                                        // backtracking step, remove the last added candidate to explore other combinations
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> temp; // to store the current combination

        sort(candidates.begin(), candidates.end()); // sort the candidates to handle duplicates easily

        solve(candidates, temp, target, 0); // start the recursive function with the initial index 0

        return result;
    }
};