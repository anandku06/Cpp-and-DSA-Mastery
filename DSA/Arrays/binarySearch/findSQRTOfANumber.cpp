// Find square root of a number
// Medium

// Hints
// Company
// Given a positive integer n. Find and return its square root. If n is not a perfect square, then return the floor value of sqrt(n).

// Example 1

// Input: n = 36

// Output: 6

// Explanation: 6 is the square root of 36.

// Example 2

// Input: n = 28

// Output: 5

// Explanation: The square root of 28 is approximately 5.292. So, the floor value will be 5.

// Now your turn!

// Input: n=50

// Output:

// Correct

// 50

// 8

// 7

// 1
// Constraints

//  0 <= n <= 231 - 1

// approach: The problem can be solved using binary search. We can set the left pointer to 0 and the right pointer to n. Then, we can calculate the mid value and check if mid * mid is equal to n. If it is, we return mid. If mid * mid is less than n, we move the left pointer to mid + 1. If mid * mid is greater than n, we move the right pointer to mid - 1. We continue this process until the left pointer is greater than the right pointer. Finally, we return the right pointer as the floor value of sqrt(n).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int floorSqrt(int n)
    {
        if (n == 0 || n == 1)
            return n; // base case: if n is 0 or 1, return n

        int left = 1, right = n; // initialize left and right pointers

        while (left <= right)
        {
            int mid = left + (right - left) / 2; // calculate mid value
            long long val = 1LL * mid * mid;     // calculate mid * mid to avoid overflow

            if (val == n)
                return mid; // if mid * mid is equal to n, return mid
            else if (val < n)
                left = mid + 1; // if mid * mid is less than n, move the left pointer to mid + 1
            else
                right = mid - 1; // if mid * mid is greater than n, move the right pointer to mid - 1
        }

        return right; // return the right pointer as the floor value of sqrt(n)
    }
};