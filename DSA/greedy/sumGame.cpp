// 1927. Sum Game
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Alice and Bob take turns playing a game, with Alice starting first.

// You are given a string num of even length consisting of digits and '?' characters. On each turn, a player will do the following if there is still at least one '?' in num:

// Choose an index i where num[i] == '?'.
// Replace num[i] with any digit between '0' and '9'.
// The game ends when there are no more '?' characters in num.

// For Bob to win, the sum of the digits in the first half of num must be equal to the sum of the digits in the second half. For Alice to win, the sums must not be equal.

// For example, if the game ended with num = "243801", then Bob wins because 2+4+3 = 8+0+1. If the game ended with num = "243803", then Alice wins because 2+4+3 != 8+0+3.
// Assuming Alice and Bob play optimally, return true if Alice will win and false if Bob will win.

// Example 1:

// Input: num = "5023"
// Output: false
// Explanation: There are no moves to be made.
// The sum of the first half is equal to the sum of the second half: 5 + 0 = 2 + 3.
// Example 2:

// Input: num = "25??"
// Output: true
// Explanation: Alice can replace one of the '?'s with '9' and it will be impossible for Bob to make the sums equal.
// Example 3:

// Input: num = "?3295???"
// Output: false
// Explanation: It can be proven that Bob will always win. One possible outcome is:
// - Alice replaces the first '?' with '9'. num = "93295???".
// - Bob replaces one of the '?' in the right half with '9'. num = "932959??".
// - Alice replaces one of the '?' in the right half with '2'. num = "9329592?".
// - Bob replaces the last '?' in the right half with '7'. num = "93295927".
// Bob wins because 9 + 3 + 2 + 9 = 5 + 9 + 2 + 7.

// Constraints:

// 2 <= num.length <= 105
// num.length is even.
// num consists of only digits and '?'.

// approach: We can use a greedy approach to solve this problem. We can keep track of the sum of the digits in the first half and the second half of the string. We can also keep track of the number of '?' characters in each half. If the sum of the first half is greater than the sum of the second half, then Alice will win. If the sum of the first half is less than the sum of the second half, then Bob will win. If the sums are equal, then we can check if there are any '?' characters in either half. If there are, then Alice will win because she can replace one of the '?' characters with a digit that will make the sums unequal. If there are no '?' characters in either half, then Bob will win because he can replace one of the '?' characters with a digit that will make the sums equal.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool sumGame(string num)
    {
        int n = num.size();
        int leftSum = 0, rightSum = 0;
        int leftCount = 0, rightCount = 0;

        for (int i = 0; i < n; i++)
        {
            if (num[i] == '?')
            {
                if (i < n / 2)
                    leftCount++;
                else
                    rightCount++;
            }
            else
            {
                if (i < n / 2)
                    leftSum += num[i] - '0';
                else
                    rightSum += num[i] - '0';
            }
        }

        int totalCount = leftCount + rightCount;
        if (totalCount % 2 == 1)
            return true;

        int LEFT = 2 * leftSum + 9 * leftCount;    // Maximum possible sum for the left half
        int RIGHT = 2 * rightSum + 9 * rightCount; // Maximum possible sum for the right half

        return LEFT != RIGHT;
    }
};

/**
 * Logic of this : 2 * leftSum + 9 * leftCount;
 * This represents the maximum possible sum for the left half of the string.
 * The term 2 * leftSum accounts for the sum of the digits in the left half, while 9 * leftCount accounts for the maximum possible contribution from the '?' characters in the left half. Since each '?' can be replaced with a digit between '0' and '9', the maximum contribution from each '?' is 9. Therefore, by multiplying the number of '?' characters (leftCount) by 9, we get the maximum possible sum that can be achieved by replacing all '?' characters in the left half with '9's.
 * Similarly, 2 * rightSum + 9 * rightCount represents the maximum possible sum for the right half of the string, taking into account the sum of the digits in the right half and the maximum possible contribution from the '?' characters in the right half.
 * By comparing the maximum possible sums for the left and right halves, we can determine if Alice can win the game. If the maximum possible sum for the left half is not equal to the maximum possible sum for the right half, then Alice can make a move that will result in unequal sums, and she will win. Otherwise, if the maximum possible sums are equal, Bob can always make a move that will result in equal sums, and he will win.
 */

// in Java

/*
class Solution {
    public boolean sumGame(String num) {
        int n = num.length();
        int leftSum = 0, rightSum = 0;
        int leftCount = 0, rightCount = 0;

        for (int i = 0; i < n; i++) {
            if (num.charAt(i) == '?') {
                if (i < n / 2)
                    leftCount++;
                else
                    rightCount++;
            } else {
                if (i < n / 2)
                    leftSum += num.charAt(i) - '0';
                else
                    rightSum += num.charAt(i) - '0';
            }
        }

        int totalCount = leftCount + rightCount;
        if (totalCount % 2 == 1)
            return true;

        int LEFT = 2 * leftSum + 9 * leftCount;    // Maximum possible sum for the left half
        int RIGHT = 2 * rightSum + 9 * rightCount; // Maximum possible sum for the right half

        return LEFT != RIGHT;
    }
}
*/