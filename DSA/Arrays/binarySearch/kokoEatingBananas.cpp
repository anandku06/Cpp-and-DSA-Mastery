// 875. Koko Eating Bananas
// Medium
// Topics
// premium lock icon
// Companies
// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4
// Example 2:

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30
// Example 3:

// Input: piles = [30,11,23,4,20], h = 6
// Output: 23

// Constraints:

// 1 <= piles.length <= 104
// piles.length <= h <= 109
// 1 <= piles[i] <= 109

// approach: Using Binary Search
// Intuition
// We can use binary search to find the minimum eating speed k. The minimum possible value of k is 1 (if Koko eats one banana per hour) and the maximum possible value of k is the maximum number of bananas in any pile (if Koko eats all the bananas in the largest pile in one hour). We will initialize left to 1 and right to the maximum number of bananas in any pile. We will calculate the mid value and check if Koko can eat all the bananas within h hours at that eating speed. If she can, we will move the right pointer to mid; otherwise, we will move the left pointer to mid + 1. We will continue this process until left is less than right, at which point left will be the minimum eating speed that allows Koko to eat all the bananas within h hours.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
// Helper function to check if Koko can eat all bananas within h hours at eating speed k
    bool canEatAllBananas(vector<int> &piles, int h, int k)
    {
        // Calculate the total hours needed to eat all bananas at eating speed k
        int hoursNeeded = 0;

        // For each pile, calculate the hours needed to eat that pile at speed k
        for (int pile : piles)
        {
            hoursNeeded += (pile + k - 1) / k; // equivalent to ceil(pile / k)
        }

        return hoursNeeded <= h; // check if Koko can eat all bananas within h hours at eating speed k
    }

public:
    int minEatingBananas(vector<int> &piles, int h)
    {
        int left = 1;                                         // minimum eating speed is 1 banana per hour
        int right = *max_element(piles.begin(), piles.end()); // maximum eating speed is the maximum number of bananas in any pile

        while (left < right)
        {
            int mid = left + (right - left) / 2; // eating speed to check

            if (canEatAllBananas(piles, h, mid)) // if Koko can eat all bananas at this eating speed
                right = mid;                     // try to find a smaller eating speed
            else
                left = mid + 1; // need to increase the eating speed
        }
        return left; // left is the minimum eating speed that allows Koko to eat all the bananas within h hours
    }
};