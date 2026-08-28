// 191. Number of 1 Bits
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

// Example 1:

// Input: n = 11

// Output: 3

// Explanation:

// The input binary string 1011 has a total of three set bits.

// Example 2:

// Input: n = 128

// Output: 1

// Explanation:

// The input binary string 10000000 has a total of one set bit.

// Example 3:

// Input: n = 2147483645

// Output: 30

// Explanation:

// The input binary string 1111111111111111111111111111101 has a total of thirty set bits.

// Constraints:

// 1 <= n <= 231 - 1

// Follow up: If this function is called many times, how would you optimize it?

// approach: use Brian Kernighan's algorithm, which repeatedly removes the last set bit from the number until it becomes 0.
// why it works: each time we perform n = n & (n - 1), we remove the last set bit from n, and we can count how many times we do this until n becomes 0.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;

        while (n > 0)
        {
            n = n & (n - 1); // remove the last set bit from n
            count++;         // increment the count of set bits
        }

        return count; // return the total count of set bits
    }
};