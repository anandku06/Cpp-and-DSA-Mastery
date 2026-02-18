// 693. Binary Number With Alternating Bits

// Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

// Example 1:

// Input: n = 5
// Output: true
// Explanation: The binary representation of 5 is: 101
// Example 2:

// Input: n = 7
// Output: false
// Explanation: The binary representation of 7 is: 111.
// Example 3:

// Input: n = 11
// Output: false
// Explanation: The binary representation of 11 is: 1011.

// Constraints:

// 1 <= n <= 231 - 1

// Intuition
// If a number has alternating bits (like 101010...), then shifting it right by 1 bit will create an opposite pattern.

// When we XOR the number with its right-shifted version:

// x = n ^ (n >> 1)
// If the bits were perfectly alternating, the result will be a sequence of all 1s (e.g., 11111...).

// A number that is all 1s has a special property:

// x & (x + 1) == 0
// This works because adding 1 to a sequence of all 1s produces a power of two, and ANDing them gives 0.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        unsigned int x = n ^ (n >> 1);

        return (x & (x + 1)) == 0;
    }
};