// 1011. Capacity To Ship Packages Within D Days
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// A conveyor belt has packages that must be shipped from one port to another within days days.

// The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

// Example 1:

// Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
// Output: 15
// Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
// 1st day: 1, 2, 3, 4, 5
// 2nd day: 6, 7
// 3rd day: 8
// 4th day: 9
// 5th day: 10

// Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
// Example 2:

// Input: weights = [3,2,2,4,1,4], days = 3
// Output: 6
// Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
// 1st day: 3, 2
// 2nd day: 2, 4
// 3rd day: 1, 4
// Example 3:

// Input: weights = [1,2,3,1,1], days = 4
// Output: 3
// Explanation:
// 1st day: 1
// 2nd day: 2
// 3rd day: 3
// 4th day: 1, 1

// Constraints:

// 1 <= days <= weights.length <= 5 * 104
// 1 <= weights[i] <= 500

// approach: Binary Search
// Intuition
// We can use binary search to find the minimum capacity of the ship that can ship all the packages within the given number of days. The minimum capacity of the ship should be at least the maximum weight of a single package, and the maximum capacity can be the sum of all package weights. We will perform binary search between these two values to find the optimal capacity.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canShip(vector<int> &weights, int days, int capacity)
    {
        int currentLoad = 0;  // current load of the ship
        int requiredDays = 1; // number of days required to ship all packages

        for (int weight : weights)
        {
            if (currentLoad + weight > capacity) // if adding the current package exceeds the capacity
            {
                requiredDays++;  // we need an additional day
                currentLoad = 0; // reset the current load for the new day
            }
            currentLoad += weight; // add the current package to the load
        }

        return requiredDays <= days; // check if we can ship all packages within the given days
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int left = *max_element(weights.begin(), weights.end());   // minimum capacity of the ship
        int right = accumulate(weights.begin(), weights.end(), 0); // maximum capacity of the ship

        while (left < right)
        {
            int mid = left + (right - left) / 2; // mid capacity of the ship
            if (canShip(weights, days, mid))     // check if we can ship all packages within the given days with mid capacity
                right = mid;                     // if yes, try to find a smaller capacity
            else
                left = mid + 1; // if no, increase the capacity
        }

        return left; // return the minimum capacity of the ship
    }
};