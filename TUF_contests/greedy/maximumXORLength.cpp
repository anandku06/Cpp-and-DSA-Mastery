// Maximum XOR Length
// Easy

// Viper has mastered full stack web development and he wants to master the CP (competitive programming). So he commenced solving CP questions. Viper hates the questions which include bitwise operations as he thinks they're a headache for solving.

// While solving he encountered a query totally based on bitwise operation. He isn't inquisitive about solving, so he asks his pal (that is you) to clear up the hassle for him.

// You're given a binary string ( consisting of 0's and 1's.) of length n. You need to return the maximum length of the substring such that the XOR of the characters of that substring is maximum.

// Substring : A substring s[l, r] (1 ≤ l ≤ r ≤ n) of string s = s1s2....sn is string slsl+1....sr.

// Example 1

// Input : s = "11111"

// Output : 5

// Explanation : The maximum XOR that can be obtained from given string is 1.

// If we choose the complete string of length 5, then we get the maximum XOR as well.

// Example 2

// Input : s = "111111"

// Output : 5

// Explanation : The maximum XOR that can be obtained from given string is 1.

// If we choose the complete string of length 6, then we get the XOR as 0 which is not maximum.

// But if we choose the substring of length 5 (consisting of first 5 characters), then we get the XOR as 1 which is maximum.

// So maximum length with maximum XOR is 5.

// Constraints

// 1 <= n <= 105
// s = {0, 1}

// approach : The maximum XOR that can be obtained from a binary string is 1. So we need to find the maximum length of the substring such that the XOR of the characters of that substring is 1. If the complete string has an odd length, then we can choose the complete string as the substring. If the complete string has an even length, then we can choose any substring of length n-1 (which will be odd) to get the maximum XOR as 1.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumXORLength(string s)
    {
        int n = s.length();

        int ones = 0, zeros = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                ones++;
        }
    }
};