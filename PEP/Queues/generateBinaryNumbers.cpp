// Generate Binary Numbers
// Difficulty: EasyAccuracy: 67.48%Submissions: 69K+Points: 2
// Given a number n. The task is to generate all binary numbers with decimal values from 1 to n.

// Examples:

// Input: n = 4
// Output: ["1", "10", "11", "100"]
// Explanation: Binary numbers from 1 to 4 are 1, 10, 11 and 100.
// Input: n = 6
// Output: ["1", "10", "11", "100", "101", "110"]
// Explanation: Binary numbers from 1 to 6 are 1, 10, 11, 100, 101 and 110.
// Constraints:
// 1 ≤ n ≤ 106

// approach: using a queue to generate binary numbers in order. The time complexity of this approach is O(n) where n is the number of binary numbers to be generated.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> generateBinaryNumbers(int n)
    {
        // Vector to store the binary numbers
        vector<string> result;

        // Create a queue to store the binary numbers
        queue<string> q;

        // Initialize the queue with the first binary number
        q.push("1");

        // Generate binary numbers from 1 to n
        for (int i = 0; i < n; i++)
        {
            // Get the front binary number from the queue
            string current = q.front();
            q.pop();

            // Add the current binary number to the result vector
            result.push_back(current);

            // Generate the next two binary numbers by appending '0' and '1'
            q.push(current + "0");
            q.push(current + "1");
        }

        return result; // Return the vector containing binary numbers from 1 to n
    }
};