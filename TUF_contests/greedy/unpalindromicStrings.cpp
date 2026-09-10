// Un Palindromic Strings
// Medium

// A string of length n is called palindrome string if character at ith position is equal to character at (n-i+1)th position (1<= i <=ceil(n/2)).

// But Jax likes the strings which does not follow the rules of Palindromic stings. Jax likes the strings that follows given two conditions:

// 1) The character at ith position should not be equal to (n-i+1)th character for any i (1 <= i <= ceil(n/2)) (1-based indexing).

// 2) The first condition should be true for all possible strings of same length that can be produced from given string after shuffling the string in any order.

// You can perform a operation any number of times (possibly 0) so that Jax likes the given string.

// The operation is that you can change any character to its adjacent character in alphabetic order and it costs you 1 unit. The alphabetic order is cyclic in nature i.e. ‘z’ and ‘a’ are adjacent to each other.

// You have to find the minimum number of units so that given string is Un palindrome or say that it is impossible to do it by returning -1.

// Example 1

// Input : s = "abccba"

// Output : 5

// Explanation :

// Now here 1st position and 6th position violates the 1st rule of un palindromic strings. So we will change ‘a’ to some else character. For changing the ‘a’ we have two characters ‘z’ and ‘d’. To go to ‘d’ we require 3 units as the path is ‘a’ -> ‘b’ -> ‘c’ -> ‘d’. To go to ‘z’ we require only 1 unit the path is ‘a’ -> ‘z’. So we will replace one of ‘a’ with ‘z’ at a cost of ‘1’.
// Now for 2nd and 5th also violates 1st rule. So the nearest adjacent of ‘b’ are ‘y’ and ‘d’. To go to ‘y’ the path is : ‘b’ -> ‘a’ -> ‘z’ -> ‘y’. This requires 3 units. To go to ‘d’ the path is : ‘b’ -> ‘c’ -> ‘d’. This requires 2 units. So we replace one of ‘b’ with ‘d’ at a cost of 2 units.
// Now for 3rd and 4th also violates 1st rule. So the nearest adjacent of ‘c’ are ‘y’ and ‘e’. To go to ‘y’ the path is : ‘c’ -> ‘b’ -> ‘a’ -> ‘z’ -> ‘y’. This requires 4 units. To go to ‘e’ the path is : ‘c’ -> ‘d’ -> ‘e’. This requires 2 units. So we replace one of ‘c’ with ‘e’ at a cost of 2 units.

// The total cost is : 1 + 2 + 2 => 5.

// The new formed string is : zbecda. This string satisfies both the rules of un palindromic string. It can be shown that answer for this string cannot be less than this.

// Example 2

// Input : s = "xxuvva"

// Output : 2

// Explanation :

// In this if we rearrange the characters and form a string "xvuavx". In this we ca see the 1st and 6th, 2d and 5th characters are same which violets the 1st rule.
// So change the 1st occurrence of x to y with 1 unit cost.
// Change the 1st occurrence of v to w with 1 unit cost.

// So new formed string will be "ywuavx". And this string satisfies both rules.

// So total cost -> 2.

// Constraints

// 1 <= n <= 105
// s consist of lowercase english letters.

// approach : We can check if the string is un palindromic or not. If it is un palindromic then we can return 0. If it is not un palindromic then we can check if it is possible to make it un palindromic or not. If it is not possible then we can return -1. If it is possible then we can find the minimum cost to make it un palindromic.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int unPalindrome(string s)
    {
        int n = s.length();

        // If the length of the string is 1, then it is already un palindromic.
        if (n == 1)
            return 0;

        if (n > 26 || n % 2 != 0) // If the length of the string is greater than 26, then it is impossible to make it un palindromic because there are only 26 lowercase English letters. So we can return -1.
            return -1;

        // Count the frequency of each character in the string.
        vector<int> freq(26, 0);
        for (char c : s)
        {
            freq[c - 'a']++;
        }

        vector<bool> used(26, false); // To keep track of which characters have been used in the un palindromic string.

        // reserve the characters that are already used in the string to avoid using them again.
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                used[i] = true;
                freq[i]--;
            }
        }

        int cost = 0;

        // loop until all duplicates are removed and the string is un palindromic.
        while (true)
        {
            int minchar = -1;      // To keep track of the minimum character that can be used to replace the duplicate character.
            int mindist = INT_MAX; // To keep track of the minimum distance to the adjacent character.
            int usedchar = -1;     // To keep track of the character that is being used to replace the duplicate character.

            for (int i = 0; i < 26; i++)
            {
                if (freq[i] <= 0) // If the frequency of the character is 0, then we can skip it.
                    continue;

                for (int j = 0; j < 26; j++)
                {
                    if (used[j]) // If the character is already used, then we can skip it.
                        continue;

                    int dist = min(abs(i - j), 26 - abs(i - j)); // Calculate the distance to the adjacent character.

                    if (dist < mindist) // If the distance is less than the minimum distance, then we can update the minimum distance and the character that is being used to replace the duplicate character.
                    {
                        mindist = dist;
                        minchar = j;
                        usedchar = i;
                    }
                }
            }

            if (minchar == -1) // If there is no character that can be used to replace the duplicate character, then we can break the loop.
                break;

            used[minchar] = true; // Mark the character that is being used to replace the duplicate character as used.
            freq[usedchar]--;     // Decrease the frequency of the character that is being used to replace the duplicate character.
            cost += mindist;      // Add the distance to the cost.
        }

        return cost; // Return the total cost to make the string un palindromic.
    }
};