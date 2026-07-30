// 216. Combination Sum III
// Medium
// Topics
// premium lock icon
// Companies
// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.
// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6],[1,3,5],[2,3,4]]
// Explanation:
// 1 + 2 + 6 = 9
// 1 + 3 + 5 = 9
// 2 + 3 + 4 = 9
// There are no other valid combinations.
// Example 3:

// Input: k = 4, n = 1
// Output: []
// Explanation: There are no valid combinations.
// Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.

// Constraints:

// 2 <= k <= 9
// 1 <= n <= 60

// approach: Using Backtracking
// Intuition
// The problem can be solved using backtracking. We can maintain a vector to store the current combination of numbers and a variable to keep track of the current sum. We start with an empty combination and a sum of 0, and we iterate through the numbers from 1 to 9. For each number, we can either include it in the current combination or skip it. If we include it, we add it to the current combination and update the sum. If the sum becomes equal to n and the size of the combination is equal to k, we have found a valid combination and we add it to the result. If the sum exceeds n or the size of the combination exceeds k, we backtrack by removing the last number added to the combination and continue with the next number.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtrack(int k, int n, int start, vector<int> &combination, vector<vector<int>> &result)
    {
        // base case: if the size of the combination is equal to k and the sum is equal to n, we have found a valid combination
        if (combination.size() == k && n == 0)
        {
            result.push_back(combination); // add the current combination to the result
            return;
        }

        // iterate through the numbers from start to 9
        for (int i = start; i <= 9; i++)
        {
            // if the current number is greater than the remaining sum, we can break the loop as all subsequent numbers will also be greater
            if (i > n)
                break;

            combination.push_back(i);                        // include the current number in the combination
            backtrack(k, n - i, i + 1, combination, result); // recursively call the function with the updated sum and next starting number
            combination.pop_back();                          // backtrack by removing the last number added to the combination
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> result;              // to store the final result
        vector<int> combination;                 // to store the current combination
        backtrack(k, n, 1, combination, result); // call the backtracking function starting from number 1
        return result;                           // return the final result
    }
};