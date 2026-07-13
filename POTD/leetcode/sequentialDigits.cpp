// 1291. Sequential Digits
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

// Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

// Example 1:

// Input: low = 100, high = 300
// Output: [123,234]
// Example 2:

// Input: low = 1000, high = 13000
// Output: [1234,2345,3456,4567,5678,6789,12345]

// Constraints:

// 10 <= low <= high <= 10^9

// approach: Using Brute Force
// Intuition
// To find all integers with sequential digits in the range [low, high], we can generate all possible sequential digit numbers and filter them based on the given range. Sequential digit numbers are formed by taking consecutive digits from 1 to 9. We can generate these numbers by iterating through the starting digit and the length of the number.

// approach: Optimized Approach (BFS)
// Intuition
// Instead of generating all possible sequential digit numbers and filtering them, we can use a breadth-first search (BFS) approach to generate only the valid sequential digit numbers within the given range. We can start with the digits 1 to 9 and iteratively build larger numbers by appending the next consecutive digit. We will stop generating numbers once they exceed the upper limit of the range.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> result;
        queue<int> q;

        // Initialize the queue with single-digit sequential numbers
        for (int i = 1; i <= 9; i++)
        {
            q.push(i);
        }

        while (!q.empty())
        {
            int num = q.front();
            q.pop();

            // If the number is within the range, add it to the result
            if (num >= low && num <= high)
            {
                result.push_back(num);
            }

            // Generate the next sequential number by appending the next digit
            int lastDigit = num % 10;
            if (lastDigit < 9) // Ensure we don't exceed digit '9'
            {
                int nextNum = num * 10 + (lastDigit + 1);
                if (nextNum <= high) // Only enqueue if it's within the upper limit
                {
                    q.push(nextNum);
                }
            }
        }

        sort(result.begin(), result.end()); // Sort the result before returning
        return result;
    }
};
