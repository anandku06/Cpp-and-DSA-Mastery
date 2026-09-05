// 57. Insert Interval
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

// Two intervals are considered overlapping if they share at least one point.

// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

// Return intervals after the insertion.

// Note that you don't need to modify intervals in-place. You can make a new array and return it.

// Example 1:

// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
// Example 2:

// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

// Constraints:

// 0 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 105
// intervals is sorted by starti in ascending order.
// newInterval.length == 2
// 0 <= start <= end <= 105

// approach: The problem can be solved using a greedy algorithm. We can iterate through the intervals and check if the current interval overlaps with the new interval. If it does, we merge the two intervals by updating the start and end of the new interval. If it doesn't, we add the current interval to the result. Finally, we add the new interval to the result and return it.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> result; // vector to store the result intervals
        int n = intervals.size();   // get the number of intervals
        int i = 0;                  // initialize the index for iterating through intervals

        // add all intervals that come before the new interval
        while (i < n && intervals[i][1] < newInterval[0])
        {
            result.push_back(intervals[i]); // add the current interval to the result
            i++;                            // move to the next interval
        }

        // merge all overlapping intervals with the new interval
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]); // update the start of the new interval
            newInterval[1] = max(newInterval[1], intervals[i][1]); // update the end of the new interval
            i++;                                                   // move to the next interval
        }

        result.push_back(newInterval); // add the merged new interval to the result

        // add all remaining intervals that come after the new interval
        while (i < n)
        {
            result.push_back(intervals[i]); // add the current interval to the result
            i++;                            // move to the next interval
        }

        return result; // return the final list of non-overlapping intervals
    }
};