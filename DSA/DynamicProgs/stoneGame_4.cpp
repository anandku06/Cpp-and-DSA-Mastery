// 1510. Stone Game IV
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Alice and Bob take turns playing a game, with Alice starting first.

// Initially, there are n stones in a pile. On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.

// Also, if a player cannot make a move, he/she loses the game.

// Given a positive integer n, return true if and only if Alice wins the game otherwise return false, assuming both players play optimally.

// Example 1:

// Input: n = 1
// Output: true
// Explanation: Alice can remove 1 stone winning the game because Bob doesn't have any moves.
// Example 2:

// Input: n = 2
// Output: false
// Explanation: Alice can only remove 1 stone, after that Bob removes the last one winning the game (2 -> 1 -> 0).
// Example 3:

// Input: n = 4
// Output: true
// Explanation: n is already a perfect square, Alice can win with one move, removing 4 stones (4 -> 0).

// Constraints:

// 1 <= n <= 105

// approach: Using Dynamic Programming
// Intuition
// The problem can be solved using dynamic programming. We can maintain a 1D array dp where dp[i] represents whether the current player can win with i stones remaining. The base case is when i == 0, where the current player loses, so dp[0] = false. For other cases, we can iterate through all possible square numbers j (where j*j <= i) and check if there exists a move that leads to a losing position for the opponent (i.e., dp[i - j*j] == false). If such a move exists, we set dp[i] = true. Finally, we return dp[n] as the result.

#include <bits/stdc++.h>
using namespace std;

// recursion + memoization
class Solution
{
public:
    bool solve(int n, vector<int> &dp)
    {
        if (n == 0) // base case: if there are no stones left, the current player loses
            return false;

        if (dp[n] != -1) // if the result is already computed, return it
            return dp[n];

        for (int i = 1; i * i <= n; i++) // iterate through all possible square numbers
        {
            if (!solve(n - i * i, dp)) // if there exists a move that leads to a losing position for the opponent
            {
                return dp[n] = true; // the current player can win
            }
        }

        return dp[n] = false; // if no winning move is found, the current player loses
    }

    bool winnerSquareGame(int n)
    {
        vector<int> dp(n + 1, -1); // create a dp array to store the result for each number of stones

        return solve(n, dp); // call the recursive function to determine if Alice can win with n stones
    }
};

// bottom-up approach
class Solution
{
public:
    bool winnerSquareGame(int n)
    {
        vector<bool> dp(n + 1, false); // create a dp array to store whether the current player can win with i stones remaining

        for (int i = 1; i <= n; i++) // iterate through all numbers of stones from 1 to n
        {
            for (int j = 1; j * j <= i; j++) // iterate through all possible square numbers
            {
                if (!dp[i - j * j]) // if there exists a move that leads to a losing position for the opponent
                {
                    dp[i] = true; // the current player can win
                    break;        // no need to check further square numbers
                }
            }
        }

        return dp[n]; // return whether Alice can win with n stones
    }
};