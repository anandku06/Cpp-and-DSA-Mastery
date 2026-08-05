// 486. Predict the Winner
// Medium
// Topics
// premium lock icon
// Companies
// You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

// Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

// Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

// Example 1:

// Input: nums = [1,5,2]
// Output: false
// Explanation: Initially, player 1 can choose between 1 and 2.
// If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2).
// So, final score of player 1 is 1 + 2 = 3, and player 2 is 5.
// Hence, player 1 will never be the winner and you need to return false.
// Example 2:

// Input: nums = [1,5,233,7]
// Output: true
// Explanation: Player 1 first chooses 1. Then player 2 has to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
// Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.

// Constraints:

// 1 <= nums.length <= 20
// 0 <= nums[i] <= 107

// approach: Using Dynamic Programming
// Intuition
// The problem can be solved using dynamic programming. We can maintain a 2D array dp where dp[i][j] represents the maximum score difference that the current player can achieve starting from index i to index j. The base case is when i == j, where there is only one stone left, so dp[i][i] = nums[i]. For other cases, we can either take the leftmost or rightmost stone and calculate the score difference for each option. We can fill up the dp array using these relations and finally return true if dp[0][n-1] >= 0, indicating that player 1 can win or tie.

#include <bits/stdc++.h>
using namespace std;

// recursion + memoization
class Solution
{
public:
    int solve(int left, int right, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (left == right) // base case: if there's only one stone left, return its value
        {
            return nums[left];
        }

        if (dp[left][right] != INT_MIN) // if we have already calculated the maximum score difference for this range, return it
        {
            return dp[left][right];
        }

        // calculate the maximum score difference by taking either the leftmost or rightmost stone
        int takeLeft = nums[left] - solve(left + 1, right, nums, dp);   // take the leftmost stone and calculate the score difference
        int takeRight = nums[right] - solve(left, right - 1, nums, dp); // take the rightmost stone and calculate the score difference

        dp[left][right] = max(takeLeft, takeRight); // store the maximum score difference for this range

        return dp[left][right]; // return the maximum score difference for this range
    }

    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size();                                // get the size of the input array
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN)); // create a 2D dp array to store the maximum score difference

        int diff = solve(0, n - 1, nums, dp); // calculate the maximum score difference starting from index 0 to n-1

        return diff >= 0; // if the score difference is non-negative, player 1 can win or tie
    }
};