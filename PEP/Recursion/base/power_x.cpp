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

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int myPow(int x, long long n) { // to avoid overflow conditions
            if(n < 0) { // handling the edge case, if n is negative
                n *= -1;
                x = 1/x;
            }

            if(n == 0) return 1;

            return n & 1 ? x * myPow(x, n - 1) : myPow(x * x, n / 2);
        }
};