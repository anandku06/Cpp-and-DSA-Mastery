// Count Set Cost
// Easy

// Given two integers n and k, return the cost of flipping all set bits in n. One flip operation costs k.

// Example 1

// Input: n = 9, k = 10

// Output: 20

// Explanation: Binary representation of 9 = 1001.

// Number of set bits = 2, therefore cost = 2 * 10 = 20.

// Example 2

// Input: n = 8, k = 5

// Output: 5

// Explanation: Binary representation of 8 = 1000.

// Number of set bits = 1, therefore cost = 1 * 5 = 5.

// Constraints

// 0 <= n < 231
// 0 <= k <= 104

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int setBitCost(int n, int k)
    {
        int count = 0; // initialize a counter for set bits

        while (n > 0)
        {
            if (n & 1) // check if the least significant bit is set
            {
                count++; // increment the counter if the bit is set
            }
            n >>= 1; // right shift n to check the next bit
        }

        return count * k; // return the total cost of flipping all set bits
    }
};