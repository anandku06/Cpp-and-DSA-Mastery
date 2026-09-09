// 3871. Count Commas in Range II
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer n.

// Return the total number of commas used when writing all integers from [1, n] (inclusive) in standard number formatting.

// In standard formatting:

// A comma is inserted after every three digits from the right.
// Numbers with fewer than 4 digits contain no commas.

// Example 1:

// Input: n = 1002

// Output: 3

// Explanation:

// The numbers "1,000", "1,001", and "1,002" each contain one comma, giving a total of 3.

// Example 2:

// Input: n = 998

// Output: 0

// Explanation:

// ​​​​​​​All numbers from 1 to 998 have fewer than four digits. Therefore, no commas are used.

// Constraints:

// 1 <= n <= 1015

// approach: To solve this problem, we can iterate through the range of numbers from 1 to n and count the number of commas used in each number. We can determine the number of commas in a number by checking its length. If the length is greater than or equal to 4, we can calculate the number of commas as (length - 1) / 3. We can keep a running total of the commas counted and return that total at the end.

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution
{
public:
    long long countCommas(long long n)
    {
        ll lower = 1000, upper;
        ll result = 0;
        ll commas = 1;

        while (lower <= n)
        {
            upper = lower * 1000 - 1;
            if (upper > n)
                upper = n;

            ll count = upper - lower + 1;
            result += count * commas;

            lower *= 1000;
            commas++;
        }

        return result;
    }
};