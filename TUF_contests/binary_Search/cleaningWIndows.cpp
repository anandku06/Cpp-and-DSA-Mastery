// Cleaning Windows
// Medium

// A building has n floors, with the ith floor having windows[i-1] windows to clean. A worker has h hours to clean all windows.

// Return the minimum number of windows he has to clean each hour to finish the job within the deadline. If his speed is k windows/hour and he is on a floor with less than k windows, he will clean those windows and not go to another floor till the hour is complete. If it cannot be completed return -1.

// Example 1

// Input: windows = [5, 7, 1, 8], h = 8.

// Output: 4

// Explanation: For k = 3, time needed = 5/3 + 7/3 + 1/3 + 8/3 = 2 + 3 + 1 + 3 = 9

// for k = 4, time needed = 5/4 + 7/4 + 1/4 + 8/4 = 2 + 2 + 1 + 2 = 7, thus 4 is the minimum speed needed.

// Example 2

// Input: windows = [5, 7, 8, 9, 10], h = 4.

// Output: -1

// Explanation: The minimum time needed is 5.

// Constraints

// n == number of floors
// 0 <= n <= 105
// 1 <= windows[i] <= 5000
// 1 <= h <= 5 * 105

// Approach: Using Binary Search
// Intuition
// We can use binary search to find the minimum number of windows the worker has to clean each hour. The minimum possible value of k is 1 (if the worker cleans one window per hour) and the maximum possible value of k is the maximum number of windows on any floor (if the worker cleans all the windows on the floor with the most windows in one hour). We will initialize left to 1 and right to the maximum number of windows on any floor. We will calculate the mid value and check if the worker can clean all the windows within h hours at that cleaning speed. If he can, we will move the right pointer to mid; otherwise, we will move the left pointer to mid + 1. We will continue this process until left is less than right, at which point left will be the minimum cleaning speed that allows the worker to clean all the windows within h hours.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int cleaningWindows(vector<int> &windows, int h)
    {
        int n = windows.size(); // number of floors
        if (n == 0)             // if there are no floors, no windows to clean
            return 0;

        if (n > h) // if there are more floors than hours, it's impossible to clean all windows
            return -1;

        int left = 1;                                             // minimum cleaning speed is 1 window per hour
        int right = *max_element(windows.begin(), windows.end()); // maximum cleaning speed is the maximum number of windows on any floor

        while (left < right)
        {
            int mid = left + (right - left) / 2; // cleaning speed to check
            long long hoursNeeded = 0;           // total hours needed to clean all windows at this speed

            for (int w : windows)
            {
                hoursNeeded += (w + mid - 1) / mid; // equivalent to ceil(w / mid)
            }

            if (hoursNeeded <= h) // if the worker can clean all windows at this speed
                right = mid;      // try to find a smaller cleaning speed
            else
                left = mid + 1; // try to find a larger cleaning speed
        }

        return left; // left will be the minimum cleaning speed that allows the worker to clean all windows within h hours
    }
};