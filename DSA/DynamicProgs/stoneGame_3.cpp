// 1406. Stone Game III
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

// Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.

// The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially.

// The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.

// Assume Alice and Bob play optimally.

// Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will end the game with the same score.

// Example 1:

// Input: stoneValue = [1,2,3,7]
// Output: "Bob"
// Explanation: Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.
// Example 2:

// Input: stoneValue = [1,2,3,-9]
// Output: "Alice"
// Explanation: Alice must choose all the three piles at the first move to win and leave Bob with negative score.
// If Alice chooses one pile her score will be 1 and the next move Bob's score becomes 5. In the next move, Alice will take the pile with value = -9 and lose.
// If Alice chooses two piles her score will be 3 and the next move Bob's score becomes 3. In the next move, Alice will take the pile with value = -9 and also lose.
// Remember that both play optimally so here Alice will choose the scenario that makes her win.
// Example 3:

// Input: stoneValue = [1,2,3,6]
// Output: "Tie"
// Explanation: Alice cannot win this game. She can end the game in a draw if she decided to choose all the first three piles, otherwise she will lose.

// Constraints:

// 1 <= stoneValue.length <= 5 * 104
// -1000 <= stoneValue[i] <= 1000

// approach: Using Dynamic Programming
// Intuition
// The problem can be solved using dynamic programming. We can maintain a 1D array dp where dp[i] represents the maximum score difference that the current player can achieve starting from index i. The base case is when i == n, where there are no stones left, so dp[n] = 0. For other cases, we can either take 1, 2, or 3 stones and calculate the score difference for each option. We can fill up the dp array using these relations and finally return the result based on the value of dp[0].

#include <bits/stdc++.h>
using namespace std;

// recursion + memoization
class Solution
{
public:
    int solve(int idx, vector<int> &stoneValue, vector<int> &dp)
    {
        if (idx == stoneValue.size()) // base case: if we have taken all stones, return 0
        {
            return 0;
        }

        if (dp[idx] != INT_MIN) // if we have already calculated the maximum score difference for this index, return it
        {
            return dp[idx];
        }

        dp[idx] = stoneValue[idx] - solve(idx + 1, stoneValue, dp); // take 1 stone and calculate the score difference

        if (idx + 1 < stoneValue.size()) // if we can take 2 stones
        {
            dp[idx] = max(dp[idx], stoneValue[idx] + stoneValue[idx + 1] - solve(idx + 2, stoneValue, dp)); // take 2 stones and calculate the score difference
        }
        if (idx + 2 < stoneValue.size()) // if we can take 3 stones
        {
            dp[idx] = max(dp[idx], stoneValue[idx] + stoneValue[idx + 1] + stoneValue[idx + 2] - solve(idx + 3, stoneValue, dp)); // take 3 stones and calculate the score difference
        }

        return dp[idx]; // return the maximum score difference for this index
    }

    string stoneGameIII(vector<int> &stoneValue)
    {
        int n = stoneValue.size();

        vector<int> dp(n + 1, INT_MIN); // dp[i] represents the maximum score difference starting from index i

        int diff = solve(0, stoneValue, dp); // calculate the maximum score difference starting from index 0

        if (diff > 0) // if the score difference is positive, Alice wins
        {
            return "Alice";
        }
        else if (diff < 0) // if the score difference is negative, Bob wins
        {
            return "Bob";
        }

        return "Tie"; // if the score difference is 0, it's a tie
    }
};

// bottom-up approach
class Solution
{
public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        int n = stoneValue.size();

        vector<int> dp(n + 1); // dp[i] represents the maximum score difference starting from index i

        for (int i = n - 1; i >= 0; i--) // fill the dp array from the end to the beginning
        {
            dp[i] = stoneValue[i] - dp[i + 1]; // take 1 stone and calculate the score difference

            if (i + 1 < n) // if we can take 2 stones
            {
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] - dp[i + 2]); // take 2 stones and calculate the score difference
            }
            if (i + 2 < n) // if we can take 3 stones
            {
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]); // take 3 stones and calculate the score difference
            }
        }

        if (dp[0] > 0) // if the score difference is positive, Alice wins
        {
            return "Alice";
        }
        else if (dp[0] < 0) // if the score difference is negative, Bob wins
        {
            return "Bob";
        }

        return "Tie"; // if the score difference is 0, it's a tie
    }
};

// constant space approach
class Solution
{
public:
    string stoneGameIII(vector<int> &stones)
    {
        int n = stones.size(); // get the number of stones

        int a = 0, b = 0, c = 0; // initialize the maximum score differences for the last three indices

        for (int i = n - 1; i >= 0; i--) // iterate from the last stone to the first
        {
            int curr = stones[i] - a; // take 1 stone and calculate the score difference

            if (i + 1 <= n) // if we can take 2 stones
            {
                curr = max(curr, stones[i] + stones[i + 1] - b); // take 2 stones and calculate the score difference
            }
            if (i + 2 <= n) // if we can take 3 stones
            {
                curr = max(curr, stones[i] + stones[i + 1] + stones[i + 2] - c); // take 3 stones and calculate the score difference
            }

            c = b; // update the maximum score differences for the last three indices
            b = a;
            a = curr;
        }
    }
};