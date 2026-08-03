// 877. Stone Game
// Medium
// Topics
// premium lock icon
// Companies
// Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

// The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

// Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

// Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

// Example 1:

// Input: piles = [5,3,4,5]
// Output: true
// Explanation:
// Alice starts first, and can only take the first 5 or the last 5.
// Say she takes the first 5, so that the row becomes [3, 4, 5].
// If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
// If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
// This demonstrated that taking the first 5 was a winning move for Alice, so we return true.
// Example 2:

// Input: piles = [3,7,2,3]
// Output: true

// Constraints:

// 2 <= piles.length <= 500
// piles.length is even.
// 1 <= piles[i] <= 500
// sum(piles[i]) is odd.

// approach: Using Dynamic Programming
// Intuition
// The problem can be solved using dynamic programming. We can maintain a 2D array dp where dp[i][j] represents the maximum number of stones a player can collect from piles[i] to piles[j]. The base case is when i == j, where the player can only take the pile at index i (or j), so dp[i][i] = piles[i]. For other cases, the player has two choices: take the pile at index i or take the pile at index j. If the player takes piles[i], then the opponent will play optimally on the remaining piles from i+1 to j, and the maximum stones the opponent can collect is dp[i+1][j]. Therefore, the player's score will be piles[i] + (sum of stones from i+1 to j - dp[i+1][j]). Similarly, if the player takes piles[j], then the opponent will play optimally on the remaining piles from i to j-1, and the maximum stones the opponent can collect is dp[i][j-1]. Therefore, the player's score will be piles[j] + (sum of stones from i to j-1 - dp[i][j-1]). We can fill up the dp array using these relations and finally check if Alice's score is greater than Bob's score.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();                         // get the size of the input array
        vector<vector<int>> dp(n, vector<int>(n, 0)); // create a 2D dp array to store the maximum stones a player can collect from piles[i] to piles[j]

        // fill the base case where i == j
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = piles[i]; // if there's only one pile, the player takes it
        }

        // fill the dp array for all other cases
        for (int len = 2; len <= n; len++) // length of the subarray
        {
            for (int i = 0; i <= n - len; i++) // starting index of the subarray
            {
                int j = i + len - 1;                                                                                                    // ending index of the subarray
                int totalStones = accumulate(piles.begin() + i, piles.begin() + j + 1, 0);                                              // total stones in the current subarray
                dp[i][j] = max(piles[i] + (totalStones - piles[i] - dp[i + 1][j]), piles[j] + (totalStones - piles[j] - dp[i][j - 1])); // calculate the maximum stones a player can collect
            }
        }

        return dp[0][n - 1] > accumulate(piles.begin(), piles.end(), 0) / 2; // check if Alice's score is greater than half of the total stones
    }
};

// Recursion + Memoization

class Solution
{
public:
    int solve(vector<int> &piles, int left, int right, vector<vector<int>> &dp)
    {
        if (left > right)
            return 0; // base case: if there are no piles left, return 0

        if (dp[left][right] != -1)
            return dp[left][right]; // if the result is already computed, return it

        int takeLeft = piles[left] + min(solve(piles, left + 2, right, dp), solve(piles, left + 1, right - 1, dp));   // if the player takes the left pile, the opponent will play optimally on the remaining piles
        int takeRight = piles[right] + min(solve(piles, left + 1, right - 1, dp), solve(piles, left, right - 2, dp)); // if the player takes the right pile, the opponent will play optimally on the remaining piles

        return dp[left][right] = max(takeLeft, takeRight); // return the maximum stones a player can collect
    }

    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size(); // get the size of the input array

        int sum = accumulate(piles.begin(), piles.end(), 0); // calculate the total number of stones in all piles

        vector<vector<int>> dp(n, vector<int>(n, -1)); // create a 2D dp array to store the maximum stones a player can collect from piles[left] to piles[right]

        int aliceScore = solve(piles, 0, n - 1, dp); // calculate the maximum score Alice can achieve by playing optimally

        return aliceScore > sum / 2; // check if Alice's score is greater than half of the total stones
    }
};

// Constant Time Solution
// Observation: Since the number of piles is even and the total number of stones is odd, Alice can always win by choosing either all the even-indexed piles or all the odd-indexed piles. This is because she can always ensure that she takes the larger sum of stones by choosing the optimal strategy.

class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        return true; // Alice can always win by choosing the optimal strategy of taking either all even-indexed or all odd-indexed piles
    }
};