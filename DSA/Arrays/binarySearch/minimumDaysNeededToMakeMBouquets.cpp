// 1482. Minimum Number of Days to Make m Bouquets
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array bloomDay, an integer m and an integer k.

// You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

// The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

// Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

// Example 1:

// Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
// Output: 3
// Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
// We need 3 bouquets each should contain 1 flower.
// After day 1: [x, _, _, _, _]   // we can only make one bouquet.
// After day 2: [x, _, _, _, x]   // we can only make two bouquets.
// After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
// Example 2:

// Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
// Output: -1
// Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.
// Example 3:

// Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
// Output: 12
// Explanation: We need 2 bouquets each should have 3 flowers.
// Here is the garden after the 7 and 12 days:
// After day 7: [x, x, x, x, _, x, x]
// We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
// After day 12: [x, x, x, x, x, x, x]
// It is obvious that we can make two bouquets in different ways.

// Constraints:

// bloomDay.length == n
// 1 <= n <= 105
// 1 <= bloomDay[i] <= 109
// 1 <= m <= 106
// 1 <= k <= n

// approach: Using Binary Search
// Intuition
// We can use binary search to find the minimum number of days needed to make m bouquets. The minimum possible value of days is 1 (if all flowers bloom on the first day) and the maximum possible value of days is the maximum bloom day in the bloomDay array (if we have to wait for the last flower to bloom). We will initialize left to 1 and right to the maximum bloom day. We will calculate the mid value and check if we can make m bouquets within mid days. If we can, we will move the right pointer to mid; otherwise, we will move the left pointer to mid + 1. We will continue this process until left is less than right, at which point left will be the minimum number of days needed to make m bouquets.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canMakeBouquets(vector<int> &bloomDay, int m, int k, int days)
    {
        int bouquets = 0; // Count of bouquets made
        int flowers = 0;  // Count of adjacent flowers bloomed

        for (int bloom : bloomDay)
        {
            if (bloom <= days)
            {
                flowers++; // This flower has bloomed, increment adjacent count
                if (flowers == k)
                {
                    bouquets++;  // We can make a bouquet
                    flowers = 0; // Reset adjacent count for next bouquet
                }
            }
            else
            {
                flowers = 0; // Reset adjacent count as this flower hasn't bloomed
            }
        }

        return bouquets >= m; // Check if we can make at least m bouquets
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        if (m * k > n)
            return -1; // Not enough flowers to make m bouquets

        int left = 1;                                               // Minimum possible days
        int right = *max_element(bloomDay.begin(), bloomDay.end()); // Maximum possible days

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (canMakeBouquets(bloomDay, m, k, mid))
                right = mid; // Try to find a smaller number of days
            else
                left = mid + 1; // Need more days
        }

        return left; // Minimum number of days needed to make m bouquets
    }
};