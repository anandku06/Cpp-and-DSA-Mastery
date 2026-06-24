// 119. Pascal's Triangle II
// Easy
// Topics
// premium lock icon
// Companies
// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Example 1:

// Input: rowIndex = 3
// Output: [1,3,3,1]
// Example 2:

// Input: rowIndex = 0
// Output: [1]
// Example 3:

// Input: rowIndex = 1
// Output: [1,1]

// Constraints:

// 0 <= rowIndex <= 33

// Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?

#include <bits/stdc++.h>
using namespace std;

#include <vector>

class Solution
{
public:
    /**
     * Retrieves the 0-indexed row of Pascal's Triangle.
     * * @param rowIndex The 0-based index of the row to fetch (0 <= rowIndex <= 33).
     * @return A vector containing the integers of that specific row.
     */
    std::vector<int> getRow(int rowIndex)
    {
        // A row at `rowIndex` always contains exactly `rowIndex + 1` elements.
        std::vector<int> row(rowIndex + 1);

        // The first element of every row in Pascal's Triangle is always 1.
        row[0] = 1;

        // Calculate subsequent elements using the binomial coefficient multiplicative formula:
        // C(n, k) = C(n, k-1) * (n - k + 1) / k
        // where 'n' is rowIndex and 'k' is the current index 'i'.
        for (int i = 1; i <= rowIndex; i++)
        {
            // Use long long for the intermediate multiplication step to prevent 32-bit integer
            // overflow, which happens when rowIndex approaches 30 or higher.
            long long nextElement = ((long long)row[i - 1] * (rowIndex - i + 1)) / i;

            // Cast back to int since the final value is guaranteed to fit in a standard 32-bit integer.
            row[i] = static_cast<int>(nextElement);
        }

        return row;
    }
};