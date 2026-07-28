// 50. Pow(x,n)

// Implement the power function pow(x, n) , which calculates the x raised to n i.e. xn.

// Note : In output print 4 digits places after decimal point.

// Example 1

// Input : x = 2.0000 , n = 10

// Output : 1024.0000

// Explanation : Answer = 2^10 => 1024.

// Example 2

// Input : x = 2.0000 , n = -2

// Output : 0.2500

// Explanation : Answer = 2^(-2) = 1/4 => 0.25

// approach : using Recursion, if n is even, then we can iterate as x*x and n/2
//                              if n is odd, then x * pow(x, n - 1), making n even

/*
Concept of Binary Exponentiation is used here, which is a method to calculate the power of a number in logarithmic time complexity O(log n). The idea is to reduce the number of multiplications by using the properties of exponents.

Here's how the binary exponentiation works:
1. If n is 0, return 1 (base case).
2. If n is even, calculate the power of x*x with exponent n/2.
3. If n is odd, calculate the power of x with exponent n-1 and multiply it by x.
*/

/*
32-bit Integer Facts:
- The range of a 32-bit signed integer is from -2,147,483,648 to 2,147,483,647.
- When dealing with large exponents, we need to be careful about overflow conditions.
- 1 bit is used for the sign, 31 bits are used for the value.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myPow(int x, long long n)
    { // to avoid overflow conditions
        if (n < 0)
        { // handling the edge case, if n is negative
            n *= -1;
            x = 1 / x;
        }

        if (n == 0)
            return 1;

        return n & 1 ? x * myPow(x, n - 1) : myPow(x * x, n / 2);
    }
};