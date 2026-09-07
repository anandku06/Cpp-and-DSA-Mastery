// Minimum Platforms
// Difficulty: MediumAccuracy: 26.84%Submissions: 685K+Points: 4
// Given arrival arr[] and departure dep[] times of trains on the same day, find the minimum number of platforms needed so that no train waits. A platform cannot serve two trains at the same time; if a train arrives before another departs, an extra platform is needed.

// Note: Time intervals are in the 24-hour format (HHMM) , where the first two characters represent hour (between 00 to 23 ) and the last two characters represent minutes (this will be <= 59 and >= 0). Leading zeros for hours less than 10 are optional (e.g., 0900 is the same as 900).

// Examples:

// Input: arr[] = [900, 940, 950, 1100, 1500, 1800], dep[] = [910, 1200, 1120, 1130, 1900, 2000]
// Output: 3
// Explanation: There are three trains during the time 9:40 to 12:00. So we need a minimum of 3 platforms.
// Input: arr[] = [900, 1235, 1100], dep[] = [1000, 1240, 1200]
// Output: 1
// Explanation: All train times are mutually exclusive. So we need only one platform.
// Input: arr[] = [1000, 935, 1100], dep[] = [1200, 1240, 1130]
// Output: 3
// Explanation: All three trains have to be there from 11:00 to 11:30
// Constraints:
// 1 ≤ number of trains ≤ 105
// 0000 ≤ arr[i] ≤ dep[i] ≤ 2359

// approach: The problem can be solved using a greedy algorithm. We can sort the arrival and departure times of the trains and then use two pointers to traverse through the sorted arrays. We can keep track of the number of platforms needed at any given time by comparing the arrival and departure times. If a train arrives before the previous train departs, we need an extra platform. We can keep track of the maximum number of platforms needed during the traversal.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPlatform(vector<int> &arr, vector<int> &dep)
    {
        int n = arr.size();

        sort(arr.begin(), arr.end()); // sort the arrival times
        sort(dep.begin(), dep.end()); // sort the departure times

        int i = 0, j = 0;     // initialize two pointers for arrival and departure
        int platforms = 0;    // initialize the number of platforms needed
        int maxPlatforms = 0; // initialize the maximum number of platforms needed

        while (i < n && j < n)
        {
            if (arr[i] <= dep[j]) // if the next train arrives before the previous one departs
            {
                platforms++; // we need an extra platform
                i++;         // move to the next arrival
            }
            else // if the next train departs before the previous one arrives
            {
                platforms--; // we can free up a platform
                j++;         // move to the next departure
            }

            maxPlatforms = max(maxPlatforms, platforms); // update the maximum number of platforms needed
        }

        return maxPlatforms; // return the maximum number of platforms needed
    }
};