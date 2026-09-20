// 1401. Circle and Rectangle Overlapping
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.

// Return true if the circle and rectangle are overlapped otherwise return false. In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.

// Example 1:

// Input: radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
// Output: true
// Explanation: Circle and rectangle share the point (1,0).
// Example 2:

// Input: radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
// Output: false
// Example 3:

// Input: radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
// Output: true

// Constraints:

// 1 <= radius <= 2000
// -104 <= xCenter, yCenter <= 104
// -104 <= x1 < x2 <= 104
// -104 <= y1 < y2 <= 104

// approach: Geometry
// Intuition
// To determine if a circle and rectangle overlap, we can find the closest point on the rectangle to the center of the circle. If the distance from this closest point to the center of the circle is less than or equal to the radius of the circle, then they overlap.
// To find the closest point on the rectangle to the center of the circle, we can use the following logic:
// For the x-coordinate of the closest point, we can take the maximum of x1 and the minimum of xCenter and x2. This will give us the closest x-coordinate on the rectangle to the center of the circle.
// For the y-coordinate of the closest point, we can take the maximum of y1 and the minimum of yCenter and y2. This will give us the closest y-coordinate on the rectangle to the center of the circle.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
    {
        int xi, yi; // closest point on rectangle to circle center

        if (x1 > xCenter) // closest point is on the left edge of the rectangle
            xi = x1;
        else if (x2 < xCenter) // closest point is on the right edge of the rectangle
            xi = x2;
        else
            xi = xCenter; // closest point is on the rectangle

        if (y1 > yCenter) // closest point is on the bottom edge of the rectangle
            yi = y1;
        else if (y2 < yCenter) // closest point is on the top edge of the rectangle
            yi = y2;
        else
            yi = yCenter; // closest point is on the rectangle

        // calculate distance from closest point to circle center
        int dx = xi - xCenter;
        int dy = yi - yCenter;

        return dx * dx + dy * dy <= radius * radius; // check if distance is less than or equal to radius
    }
};