// 29. Divide Two Integers
// Medium
// Topics
// premium lock icon
// Companies
// Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

// The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

// Return the quotient after dividing dividend by divisor.

// Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

// Example 1:

// Input: dividend = 10, divisor = 3
// Output: 3
// Explanation: 10/3 = 3.33333.. which is truncated to 3.
// Example 2:

// Input: dividend = 7, divisor = -3
// Output: -2
// Explanation: 7/-3 = -2.33333.. which is truncated to -2.

// Constraints:

// -231 <= dividend, divisor <= 231 - 1
// divisor != 0

// approach: The idea is to use bit manipulation to perform the division. We can repeatedly subtract the divisor from the dividend while keeping track of the quotient. To optimize this process, we can use bit shifting to double the divisor and subtract larger chunks from the dividend. This way, we can reduce the number of iterations needed to find the quotient.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        // Handle edge cases for overflow
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX; // Overflow case
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN; // Edge case

        // Determine the sign of the result
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert both dividend and divisor to positive values
        long long ldividend = abs((long long)dividend);
        long long ldivisor = abs((long long)divisor);

        long long quotient = 0;

        while (ldividend >= ldivisor)
        {
            long long temp = ldivisor, multiple = 1;

            // Double the divisor until it exceeds the dividend
            while (ldividend >= (temp << 1))
            {
                temp <<= 1;
                multiple <<= 1;
            }

            // Subtract the largest found multiple from the dividend
            ldividend -= temp;
            quotient += multiple;
        }

        // Apply the sign to the quotient
        return isNegative ? -quotient : quotient;
    }
};

// using brute force approach
class Solution
{
public:
    int divide(int dividend, int divisor)
    {

        // Handle edge cases for overflow
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX; // Overflow case
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN; // Edge case

        // Determine the sign of the result
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert both dividend and divisor to positive values
        long long ldividend = abs((long long)dividend);
        long long ldivisor = abs((long long)divisor);

        long long quotient = 0;

        // Subtract the divisor from the dividend until the dividend is less than the divisor
        while (ldividend >= ldivisor)
        {
            ldividend -= ldivisor;
            quotient++;
        }

        // Apply the sign to the quotient
        return isNegative ? -quotient : quotient;
    }
};