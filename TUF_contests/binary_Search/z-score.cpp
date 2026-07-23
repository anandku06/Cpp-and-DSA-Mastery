// Z-Score
// Easy

// Given an array of integers marks containing the marks of a student in each subject and a multiplicative factor k. Return the Z-Score of the student.

// Z-Score is defined as the maximum value of x, where the student has at least x subjects where they have scored at least x * k.

// Example 1

// Input: marks = [62, 69, 79, 85, 45], k = 20

// Output: 3

// Explanation: Number of subjects with marks >= 3 * k = 3 * 20 = 60 -> [62, 69, 79, 85] = 4

// Number of subjects with marks >= 4 * k = 4 * 20 = 80 -> [85] = 1

// Thus, the maximum Z-Score is 3.

// Example 2

// Input: marks = [93, 64, 91, 85], k = 45

// Output: 2

// Explanation: Number of subjects with marks >= 2 * k = 2 * 45 = 90 -> [93, 91] = 2

// Number of subjects with marks >= 3 * k = 3 * 45 = 135 -> [ ] = 0

// Thus, the maximum Z-Score is 2.

// Constraints

// n == Number of subjects
// 1 <= n <= 105
// 0 <= marks[i] <= 100
// 1 <= k <= 100

// Approach: Binary Search
// Intuition
// We can use binary search to find the maximum Z-Score. The minimum possible value of Z-Score is 0 (if the student has no subjects with marks greater than or equal to 0 * k) and the maximum possible value of Z-Score is n (if the student has all subjects with marks greater than or equal to n * k). We will initialize left to 0 and right to n. We will calculate the mid value and check if the student has at least mid subjects with marks greater than or equal to mid * k. If they do, we will move the left pointer to mid + 1; otherwise, we will move the right pointer to mid - 1. We will continue this process until left is less than or equal to right, at which point right will be the maximum Z-Score that satisfies the condition.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int zScore(vector<int> &marks, int k)
    {
        int n = marks.size(); // Number of subjects
        int left = 0;         // Minimum possible Z-Score
        int right = n;        // Maximum possible Z-Score
        int result = 0;       // Variable to store the maximum Z-Score

        // here we use left <= right because we want to continue searching until the search space is exhausted. This condition allows us to explore all possible Z-Score values between 0 and n, ensuring that we find the maximum Z-Score that satisfies the condition of having at least x subjects with marks >= x * k.
        while (left <= right)
        {
            int mid = left + (right - left) / 2; // Calculate the middle Z-Score

            // Count how many subjects have marks greater than or equal to mid * k
            int count = 0;
            for (int mark : marks)
            {
                if (mark >= mid * k)
                    count++;
            }

            if (count >= mid) // If there are at least mid subjects with marks >= mid * k
            {
                result = mid;   // Update result to the current mid value
                left = mid + 1; // Try for a larger Z-Score
            }
            else
            {
                right = mid - 1; // Try for a smaller Z-Score
            }
        }

        return result; // Return the maximum Z-Score found
    }
};