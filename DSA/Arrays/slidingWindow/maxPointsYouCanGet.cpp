// 1423. Maximum Points You Can Obtain from Cards
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

// Your score is the sum of the points of the cards you have taken.

// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

// Example 1:

// Input: cardPoints = [1,2,3,4,5,6,1], k = 3
// Output: 12
// Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
// Example 2:

// Input: cardPoints = [2,2,2], k = 2
// Output: 4
// Explanation: Regardless of which two cards you take, your score will always be 4.
// Example 3:

// Input: cardPoints = [9,7,7,9,7,7,9], k = 7
// Output: 55
// Explanation: You have to take all the cards. Your score is the sum of points of all cards.

// Constraints:

// 1 <= cardPoints.length <= 105
// 1 <= cardPoints[i] <= 104
// 1 <= k <= cardPoints.length

// approach
// The problem can be solved using a sliding window approach. We need to find the maximum score by taking k cards from either the beginning or the end of the array.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        // Initialize the sum of the left side and the maximum sum
        int lsum = 0, maxSum = INT_MIN;

        // Calculate the sum of the first k cards from the left
        for (int i = 0; i < k; i++)
        {
            lsum += cardPoints[i];

            maxSum = max(maxSum, lsum);
        }

        // Initialize the right pointer and the sum of the right side
        int right = cardPoints.size() - 1;
        int rsum = 0;

        // Move the left pointer from k-1 to 0 and the right pointer from the end to the beginning
        for (int i = k - 1; i >= 0; i--)
        {
            lsum -= cardPoints[i];

            rsum += cardPoints[right--];

            maxSum = max(maxSum, lsum + rsum);
        }

        return maxSum;
    }
};