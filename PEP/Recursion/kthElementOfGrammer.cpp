// 779. Kth Element of Grammer

// We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

// For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.
// Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.

// Example 1:

// Input: n = 1, k = 1
// Output: 0
// Explanation: row 1: 0
// Example 2:

// Input: n = 2, k = 1
// Output: 0
// Explanation:
// row 1: 0
// row 2: 01
// Example 3:

// Input: n = 2, k = 2
// Output: 1
// Explanation:
// row 1: 0
// row 2: 01

// approach : at n = 1, row -> 0
//            at n = 2, row -> 0 1
//            at n = 3, row -> 0 1 1 0
//            at n = 4, row -> 0 1 1 0 1 0 0 1
//            at n = 5, row -> 0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0 ... so on.

// Observe the pattern: the first half of the row is repeated from the previous row and second half is just the complement of the first half.
// and when k's value is odd, then it's equal to the (k+1/2)th element of (n-1)th
// k's even then its equal to the k/2th element of n-1th row

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        if (n == 1)
            return 0;

        return k & 1 ? kthGrammar(n - 1, (k + 1) / 2) : kthGrammar(n - 1, k / 2) == 0;
    }
};