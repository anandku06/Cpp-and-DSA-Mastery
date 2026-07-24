// 646. Maximum Length of Pair Chain
// Medium
// Topics
// premium lock icon
// Companies
// You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

// A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

// Return the length longest chain which can be formed.

// You do not need to use up all the given intervals. You can select pairs in any order.

// Example 1:

// Input: pairs = [[1,2],[2,3],[3,4]]
// Output: 2
// Explanation: The longest chain is [1,2] -> [3,4].
// Example 2:

// Input: pairs = [[1,2],[7,8],[4,5]]
// Output: 3
// Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].

// Constraints:

// n == pairs.length
// 1 <= n <= 1000
// -1000 <= lefti < righti <= 1000

// Approach: Using Dynamic Programming
// Intuition
// The problem can be solved using dynamic programming. We can maintain an array dp where dp[i] represents the length of the longest chain that ends with the pair at index i. We initialize all elements of dp to 1, as the minimum length of chain ending at any index is 1 (the pair itself). Then, for each pair pairs[i], we check all previous pairs pairs[j] (where j < i) and if pairs[j][1] < pairs[i][0], we update dp[i] = max(dp[i], dp[j] + 1). Finally, the length of the longest chain will be the maximum value in the dp array.

// Recursion + Memoization
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<vector<int>> &pairs, int curr, int prev, vector<vector<int>> &dp)
    {
        if (curr == pairs.size())
            return 0; // base case: if we have reached the end of the array, return 0

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1]; // if the result is already computed, return it

        int take = 0; // variable to store the length of the longest chain if we take the current pair
        if (prev == -1 || pairs[prev][1] < pairs[curr][0])
            take = 1 + solve(pairs, curr + 1, curr, dp); // if we can take the current pair, add 1 to the length and move to the next pair

        int notTake = solve(pairs, curr + 1, prev, dp); // variable to store the length of the longest chain if we do not take the current pair

        return dp[curr][prev + 1] = max(take, notTake); // store and return the maximum of taking or not taking the current pair
    }

    int findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size();                              // get the size of the input array
        vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // create a 2D dp array to store the length of the longest chain ending at each index with a previous index

        return solve(pairs, 0, -1, dp); // call the recursive function to find the length of the longest chain
    }
};

// Bottom-up approach
class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size();             // get the size of the input array
        sort(pairs.begin(), pairs.end()); // sort the pairs based on the first element

        vector<int> dp(n, 1); // create a dp array to store the length of the longest chain ending at each index, initialized to 1

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (pairs[j][1] < pairs[i][0])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end()); // return the maximum value in the dp array, which is the length of the longest chain
    }
};

// Greedy approach
class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; }); // sort the pairs based on the second element

        int currEnd = INT_MIN; // variable to store the end of the current chain
        int count = 0;         // variable to store the length of the longest chain

        for (const auto &pair : pairs)
        {
            if (pair[0] > currEnd) // if the current pair can be added to the chain
            {
                currEnd = pair[1]; // update the end of the current chain
                count++;           // increment the length of the longest chain
            }
        }

        return count; // return the length of the longest chain
    }
};