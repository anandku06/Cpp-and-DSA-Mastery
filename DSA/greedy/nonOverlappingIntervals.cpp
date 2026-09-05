// 435. Non-overlapping Intervals
// Medium
// Topics
// premium lock icon
// Companies
// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

// Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

// Example 1:

// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
// Example 2:

// Input: intervals = [[1,2],[1,2],[1,2]]
// Output: 2
// Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
// Example 3:

// Input: intervals = [[1,2],[2,3]]
// Output: 0
// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

// Constraints:

// 1 <= intervals.length <= 105
// intervals[i].length == 2
// -5 * 104 <= starti < endi <= 5 * 104

// approach: The problem can be solved using a greedy algorithm. We can sort the intervals based on their end times. Then, we can iterate through the sorted intervals and keep track of the end time of the last selected interval. If the start time of the current interval is less than the end time of the last selected interval, we need to remove the current interval. Otherwise, we update the end time of the last selected interval to be the end time of the current interval. Finally, we return the count of removed intervals.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size(); // get the number of intervals

        if (n == 0) // if there are no intervals, return 0
            return 0;

        // sort the intervals based on their end times
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             {
                 if (a[1] == b[1]) // if the end times are equal, sort based on start times
                     return a[0] < b[0];
                 return a[1] < b[1]; // sort in ascending order of end times
             });

        int count = 0;             // initialize the count of removed intervals
        int end = intervals[0][1]; // initialize the end time of the last selected interval

        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] < end) // if the start time of the current interval is less than the end time of the last selected interval
            {
                count++; // increment the count of removed intervals
            }
            else
            {
                end = intervals[i][1]; // update the end time of the last selected interval
            }
        }

        return count; // return the count of removed intervals
    }
};