// Maximum Points on a Line
// Hard

// Given an array of unqiue points nums, where each point is represented as nums[i] = [xi, yi] on a 2D plane, find the maximum number of points that lie on the same line.

// Example 1

// Input: nums = [[0,0], [1,1], [2,2], [3,3]]

// Output: 4

// Explanation: All four points lie on the line with slope 1, so the maximum number of points on the same line is 4.

// Example 2

// Input: nums = [[0,1], [2,3], [4,5], [1,2], [3,4], [2,2]]

// Output: 5

// Explanation: The points [0,1], [1,2], [2,3], [3,4], and [4,5] all lie on the same straight line, so the maximum number is 5.

// Constraints

// 1 <= nums.length <= 500
// nums[i].length == 2
// -104 <= xi, yi <= 104

// Approach: Using a hash map to store the slopes of the lines formed by each pair of points. The time complexity of this approach is O(n^2) where n is the number of points.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumPointsOnALine(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n < 3)
            return n; // If there are less than 3 points, all points lie on the same line

        int maxPoints = 0;

        for (int i = 0; i < n; i++)
        {
            unordered_map<string, int> slopeCount; // Hash map to store the count of points with the same slope
            int duplicatePoints = 1;               // Count of duplicate points (same as the current point)

            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue; // Skip the same point

                if (points[i] == points[j])
                {
                    duplicatePoints++; // Increment duplicate count if the points are the same
                }
                else
                {
                    int deltaX = points[j][0] - points[i][0];
                    int deltaY = points[j][1] - points[i][1];
                    int gcdValue = __gcd(deltaX, deltaY); // Calculate GCD to reduce the slope

                    // Reduce the slope to its simplest form
                    deltaX /= gcdValue;
                    deltaY /= gcdValue;

                    // Create a unique key for the slope
                    string slopeKey = to_string(deltaY) + "/" + to_string(deltaX);
                    slopeCount[slopeKey]++;
                }
            }

            int currentMax = 0;
            for (const auto &entry : slopeCount)
            {
                currentMax = max(currentMax, entry.second); // Find the maximum count of points with the same slope
            }

            maxPoints = max(maxPoints, currentMax + duplicatePoints); // Update the global maximum
        }

        return maxPoints;
    }
};