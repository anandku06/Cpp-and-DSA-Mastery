// 326. Power of Three

// Given an integer n, return true if it is a power of three. Otherwise, return false.

// An integer n is a power of three, if there exists an integer x such that n == 3x.

 

// Example 1:

// Input: n = 27
// Output: true
// Explanation: 27 = 33
// Example 2:

// Input: n = 0
// Output: false
// Explanation: There is no x where 3x = 0.
// Example 3:

// Input: n = -1
// Output: false
// Explanation: There is no x where 3x = (-1).

// approach : using Recursive approach, divide by 3 till, num is 3, return false if n == 0 and n % 3 != 0

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool solve(int n) {
            if(n == 3) return true;

            if(n <= 0 || n % 3 != 0) return false;

            return solve(n / 3);
        }

        bool powerOfThree(int n) {
            if(n == 1) return true;

            return solve(n);
        }

        // using bit manipulation: num += num<<1;
        bool powerOfThreeUsingBits(int n) {
            int num = 1;

            while (n > 1 && num < n) 
            {
                num += num << 1;
            }

            return num == n;
            
        }
};