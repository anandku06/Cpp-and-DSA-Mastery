// 1288. Remove Covered Intervals
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.

// The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

// Return the number of remaining intervals.

// Example 1:

// Input: intervals = [[1,4],[3,6],[2,8]]
// Output: 2
// Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
// Example 2:

// Input: intervals = [[1,4],[2,3]]
// Output: 1

// Constraints:

// 1 <= intervals.length <= 1000
// intervals[i].length == 2
// 0 <= li < ri <= 105
// All the given intervals are unique.

// approach: The problem can be solved by sorting the intervals based on their starting points. After sorting, we can iterate through the intervals and keep track of the maximum ending point seen so far. If the current interval's ending point is less than or equal to the maximum ending point, it means that the current interval is covered by a previous interval, and we can skip it. Otherwise, we update the maximum ending point and count the current interval as a remaining interval. Finally, we return the count of remaining intervals.
// One problem in the sorting is that if the starting points of two intervals are the same, we need to sort them based on their ending points in descending order. This is because if two intervals have the same starting point, the one with the larger ending point will cover the other one. Therefore, we need to sort the intervals based on their starting points in ascending order and their ending points in descending order.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        // sort the intervals based on their starting points
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             {
                 if (a[0] == b[0])
                     return a[1] > b[1]; // sort by ending point in descending order
                 return a[0] < b[0];     // sort by starting point in ascending order
             });

        int count = 0;  // to keep track of the number of remaining intervals
        int maxEnd = 0; // to keep track of the maximum ending point seen so far

        for (const auto &interval : intervals)
        {
            // if the current interval's ending point is greater than the maximum ending point seen so far,
            // it means that the current interval is not covered by any previous interval
            if (interval[1] > maxEnd)
            {
                count++;              // increment the count of remaining intervals
                maxEnd = interval[1]; // update the maximum ending point
            }
        }

        return count; // return the count of remaining intervals
    }
};