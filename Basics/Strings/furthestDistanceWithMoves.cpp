// 2833. Furthest Point From Origin
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are given a string moves of length n consisting only of characters 'L', 'R', and '_'. The string represents your movement on a number line starting from the origin 0.

// In the ith move, you can choose one of the following directions:

// move to the left if moves[i] = 'L' or moves[i] = '_'
// move to the right if moves[i] = 'R' or moves[i] = '_'
// Return the distance from the origin of the furthest point you can get to after n moves.

// Example 1:

// Input: moves = "L_RL__R"
// Output: 3
// Explanation: The furthest point we can reach from the origin 0 is point -3 through the following sequence of moves "LLRLLLR".
// Example 2:

// Input: moves = "_R__LL_"
// Output: 5
// Explanation: The furthest point we can reach from the origin 0 is point -5 through the following sequence of moves "LRLLLLL".
// Example 3:

// Input: moves = "_______"
// Output: 7
// Explanation: The furthest point we can reach from the origin 0 is point 7 through the following sequence of moves "RRRRRRR".

// Constraints:

// 1 <= moves.length == n <= 50
// moves consists only of characters 'L', 'R' and '_'.

// approach
// 1. We can count the number of 'L', 'R' and '_' in the string.
// 2. The furthest point we can get to is the maximum of the following two values:
//    a. The distance we can get to by moving all '_' to the left and all 'R' to the right.
//    b. The distance we can get to by moving all '_' to the right and all 'L' to the left.

// The distance from the current position to the origin, ignoring \textit{'_'}, is ∣L−R∣. To maximize the final distance from the origin, all \textit{'_'} characters should be assigned in the same direction as the current movement, resulting in a maximum distance of ∣L−R∣+B.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int furthestDistanceFromOrigin(string moves)
    {
        int left = 0, right = 0;
        int other = 0;

        for (char i : moves)
        {
            if (i == 'L')
                left++;
            else if (i == 'R')
                right++;
            else
                other++;
        }

        return abs(left - right) + other;
    }
};