// 371. Sum of Two Integers
// Medium
// Topics
// premium lock icon
// Companies
// Given two integers a and b, return the sum of the two integers without using the operators + and -.

// Example 1:

// Input: a = 1, b = 2
// Output: 3
// Example 2:

// Input: a = 2, b = 3
// Output: 5

// Constraints:

// -1000 <= a, b <= 1000

// Approach: Bit Manipulation
// Intuition
// We can use bit manipulation to solve this problem. The sum of two integers can be calculated using the bitwise XOR operator (^) and the bitwise AND operator (&). The XOR operator gives us the sum of two bits without considering the carry, while the AND operator gives us the carry. We can keep adding the carry to the sum until there is no carry left.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            int carry = a & b; // calculate the carry
            a = a ^ b;         // calculate the sum without carry
            b = carry << 1;    // shift the carry to the left by 1 to add it in the next iteration
        }
        return a;
    }
};