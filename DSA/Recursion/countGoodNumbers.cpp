// 1922. Count Good Numbers
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

// For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
// Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

// A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

// Example 1:

// Input: n = 1
// Output: 5
// Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
// Example 2:

// Input: n = 4
// Output: 400
// Example 3:

// Input: n = 50
// Output: 564908303

// Constraints:

// 1 <= n <= 1015

// Approach: The idea is to use binary exponentiation to calculate the number of good digit strings efficiently. For even indices, there are 5 choices (0, 2, 4, 6, 8), and for odd indices, there are 4 choices (2, 3, 5, 7). Therefore, the total number of good digit strings of length n can be calculated as (5^(n/2)) * (4^(n/2)) if n is even, and (5^((n+1)/2)) * (4^(n/2)) if n is odd. We can use binary exponentiation to compute these powers efficiently.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countGoodNumbers(long long n)
    {
        const int MOD = 1e9 + 7;
        long long evenCount = (n + 1) / 2; // Count of even indices
        long long oddCount = n / 2;        // Count of odd indices

        // Calculate 5^evenCount % MOD
        long long evenPower = binaryExponentiation(5, evenCount, MOD);
        // Calculate 4^oddCount % MOD
        long long oddPower = binaryExponentiation(4, oddCount, MOD);

        // Total good numbers = (5^evenCount * 4^oddCount) % MOD
        return (evenPower * oddPower) % MOD;
    }

private:
    long long binaryExponentiation(long long base, long long exp, long long mod)
    {
        long long result = 1;
        base %= mod;
        while (exp > 0)
        {
            if (exp & 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
};