// Pascal's Triangle I
// Easy

// Given two integers r and c, return the value at the rth row and cth column (1-indexed) in a Pascal's Triangle.

// In Pascal's triangle:

// The first row contains a single element 1.

// Each row has one more element than the previous row.

// Every row starts and ends with 1.

// For all interior elements (i.e., not at the ends), the value at position (r, c) is computed as the sum of the two elements directly above it from the previous row:

// Pascal[r][c]=Pascal[r−1][c−1]+Pascal[r−1][c]
// where indexing is 1-based

// Example 1

// Input: r = 4, c = 2

// Output: 3

// Explanation:

// The Pascal's Triangle is as follows:

// 1

// 1 1

// 1 2 1

// 1 3 3 1

// ....

// Thus, value at row 4 and column 2 = 3

// Example 2

// Input: r = 5, c = 3

// Output: 6

// Explanation:

// The Pascal's Triangle is as follows:

// 1

// 1 1

// 1 2 1

// 1 3 3 1

// 1 4 6 4 1

// ....

// Thus, value at row 5 and column 3 = 6

// Constraints

// 1 <= r, c <= 30
// c <= r
// All values will fit inside a 32-bit integer.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Helper function to calculate the combination value nCr (n choose r)
    int ncr(int n, int r)
    {
        // Optimization based on symmetry: nCr is equal to nC(n-r).
        // For example, 5C4 is the same as 5C1. This minimizes the number of loop iterations.
        if (r > n - r)
            r = n - r;

        // Base case: any number choose 1 is always that number itself (nC1 = n).
        if (r == 1)
            return n;

        // Initialize the result variable to hold the final combination value.
        int res = 1;

        // Calculate the value of nCr iteratively using the formula:
        // (n * (n-1) * ... * (n-r+1)) / (1 * 2 * ... * r)
        for (int i = 0; i < r; i++)
        {
            // Multiply by the next decreasing factor from the numerator (n, n-1, n-2...)
            res *= (n - i);
            // Divide by the next increasing factor from the denominator (1, 2, 3...)
            res /= (i + 1);
        }

        // Return the computed combination value.
        return res;
    }

    // Main function to find the element at a specific row 'r' and column 'c' (1-indexed)
    int pascalTriangle_III(int r, int c)
    {
        // Convert 1-indexed row and column to 0-indexed values for the math formula.
        // The element at row 'r' and column 'c' in Pascal's Triangle is given by (r-1)C(c-1).
        return ncr(r - 1, c - 1);
    }
};