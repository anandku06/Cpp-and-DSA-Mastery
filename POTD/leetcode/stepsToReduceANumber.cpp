// 1404. Number of Steps to Reduce a Number in Binary Representation to One

// Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:

// If the current number is even, you have to divide it by 2.

// If the current number is odd, you have to add 1 to it.

// It is guaranteed that you can always reach one for all test cases.

// Example 1:

// Input: s = "1101"
// Output: 6
// Explanation: "1101" corressponds to number 13 in their decimal representation.
// Step 1) 13 is odd, add 1 and obtain 14.
// Step 2) 14 is even, divide by 2 and obtain 7.
// Step 3) 7 is odd, add 1 and obtain 8.
// Step 4) 8 is even, divide by 2 and obtain 4.
// Step 5) 4 is even, divide by 2 and obtain 2.
// Step 6) 2 is even, divide by 2 and obtain 1.
// Example 2:

// Input: s = "10"
// Output: 1
// Explanation: "10" corresponds to number 2 in their decimal representation.
// Step 1) 2 is even, divide by 2 and obtain 1.
// Example 3:

// Input: s = "1"
// Output: 0

// Constraints:

// 1 <= s.length <= 500
// s consists of characters '0' or '1'
// s[0] == '1'

// intuition:
// The idea is to simulate the process of reducing the number to 1. We can use a while loop to keep reducing the number until it becomes 1. We can use the built-in function __builtin_popcount to count the number of 1's in the binary representation of the number. If the number is even, we can divide it by 2 by right shifting it. If the number is odd, we can add 1 to it.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void divideByTwo(string &s)
    {
        s.pop_back(); // remove the last character
    }

    // 
    void addOne(string &s)
    {
        int i = s.size();

        while (i >= 0 && s[i] != '0')
        {
            s[i] = 0;
            i--;
        }

        if (i < 0)
        {
            s = '1' + s;
        }
        else
        {
            s[i] = '1';
        }
    }

public:
    int numSteps(string &s)
    {
        int N = s.size();

        int operations = 0;

        while (s.size() > 1)
        {
            N = s.size();
            if (s[N - 1] == '0')
            {
                divideByTwo(s);
            }
            else
            {
                addOne(s);
            }

            operations++;
        }

        return operations;
    }
};