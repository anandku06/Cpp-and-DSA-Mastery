// 2965. Find Missing and Repeated Values
// Easy
// Topics
// premium lock icon
// Companies
// You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.

// Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

// Example 1:

// Input: grid = [[1,3],[2,2]]
// Output: [2,4]
// Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].
// Example 2:

// Input: grid = [[9,1,7],[8,9,2],[3,4,6]]
// Output: [9,5]
// Explanation: Number 9 is repeated and number 5 is missing so the answer is [9,5].

// Constraints:

// 2 <= n == grid.length == grid[i].length <= 50
// 1 <= grid[i][j] <= n * n
// For all x that 1 <= x <= n * n there is exactly one x that is not equal to any of the grid members.
// For all x that 1 <= x <= n * n there is exactly one x that is equal to exactly two of the grid members.
// For all x that 1 <= x <= n * n except two of them there is exactly one pair of i, j that 0 <= i, j <= n - 1 and grid[i][j] == x.

#include <bits/stdc++.h>
using namespace std;

class Solution_1
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int N = n * n; // Total number of elements expected (from 1 to n^2)

        int missNum = -1, dupNum = -1;
        unordered_map<int, int> mp;

        // Count frequencies of each number in the grid
        for (int i = 0; i < n; i++)
        {
            // FIX: Changed condition from j < N to j < n to avoid out-of-bounds crash
            for (int j = 0; j < n; j++)
            {
                mp[grid[i][j]]++;
            }
        }

        // Find the missing and duplicated numbers by checking range [1, N]
        for (int k = 1; k <= N; k++)
        {
            if (!mp.count(k))
            {
                missNum = k; // Number doesn't exist in map -> Missing
            }
            else if (mp[k] > 1)
            {
                dupNum = k; // Number appears more than once -> Duplicate
            }

            // Early exit: Stop if both numbers are found
            if (missNum != -1 && dupNum != -1)
            {
                break;
            }
        }

        return {dupNum, missNum};
    }
};

class Solution_2
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int n = grid.size();
        long long N = n * n; // Total expected numbers

        // 1. Calculate Expected Sums using standard mathematical formulas
        // Expected Sum of 1 to N: N * (N + 1) / 2
        long long expectedSum = N * (N + 1) / 2;
        // Expected Sum of Squares of 1 to N: N * (N + 1) * (2N + 1) / 6
        long long expectedSumSq = N * (N + 1) * (2 * N + 1) / 6;

        long long actualSum = 0;
        long long actualSumSq = 0;

        // 2. Calculate Actual Sums from the given grid
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                long long val = grid[i][j];
                actualSum += val;
                actualSumSq += (val * val);
            }
        }

        // 3. Set up our system of linear equations
        // Let D = duplicate, M = missing
        // Equation 1: actualSum - expectedSum = D - M
        long long diffSum = actualSum - expectedSum; // This is (D - M)

        // Equation 2: actualSumSq - expectedSumSq = D^2 - M^2
        // Since (D^2 - M^2) = (D - M) * (D + M)
        long long diffSumSq = actualSumSq - expectedSumSq; // This is (D^2 - M^2)

        // Find (D + M) by dividing (D^2 - M^2) by (D - M)
        long long sumOfDM = diffSumSq / diffSum; // This is (D + M)

        // 4. Solve for D and M
        // Adding the two equations: (D - M) + (D + M) = 2D
        int dupNum = (diffSum + sumOfDM) / 2;
        // Subtracting the two equations: (D + M) - D = M
        int missNum = sumOfDM - dupNum;

        return {dupNum, missNum};
    }
};