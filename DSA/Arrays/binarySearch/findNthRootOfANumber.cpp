// Find Nth root of a number
// Medium

// Hints
// Company
// Given two numbers N and M, find the Nth root of M. The Nth root of a number M is defined as a number X such that when X is raised to the power of N, it equals M. If the Nth root is not an integer, return -1.

// Example 1

// Input: N = 3, M = 27

// Output: 3

// Explanation: The cube root of 27 is equal to 3.

// Example 2

// Input: N = 4, M = 69

// Output:-1

// Explanation: The 4th root of 69 does not exist. So, the answer is -1.

// Now your turn!

// Input: N = 4, M = 81

// Output:

// Correct

// 3

// 4

// 9

// -1
// Constraints

//   1 <= N <= 30
//   1 <= M <= 109

// approach: The problem can be solved using binary search. We can set the left pointer to 1 and the right pointer to M. Then, we can calculate the mid value and check if mid raised to the power of N is equal to M. If it is, we return mid. If mid raised to the power of N is less than M, we move the left pointer to mid + 1. If mid raised to the power of N is greater than M, we move the right pointer to mid - 1. We continue this process until the left pointer is greater than the right pointer. Finally, we return -1 if no integer root is found.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //
    int solve(int mid, int n, int m)
    {
        long long ans = 1;

        for (int i = 1; i <= n; i++)
        {
            ans *= mid;

            if (ans > m)
                return 2;
        }
        if (ans == m)
            return 1;
        return 0;
    }

    int NthRoot(int n, int m)
    {
        int left = 1, right = m; // initialize left and right pointers

        while (left <= right)
        {
            int mid = left + (right - left) / 2; // calculate mid value
            // this pow function will cause Integer overflow, so to avoid that, using a helper function
            // long long power = pow(mid, n);       // calculate mid raised to the power of n
            int status = solve(mid, n, m);

            if (status == 1)
                return mid; // if mid raised to the power of n is equal to m, return mid
            else if (status == 0)
                left = mid + 1; // if mid raised to the power of n is less than m, move the left pointer to mid + 1
            else
                right = mid - 1; // if mid raised to the power of n is greater than m, move the right pointer to mid - 1
        }

        return -1; // if no integer root is found, return -1
    }
};