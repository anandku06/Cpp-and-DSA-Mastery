// Minimize Max Distance of Adjacent Gas Stations
// Difficulty: HardAccuracy: 38.36%Submissions: 133K+Points: 8Average Time: 40m
// We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[n-1]. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations is minimized. Find the smallest possible value of d. Find the answer exactly to 6 decimal places.

// Note: stations sorted is in a strictly increasing order.

// Examples:

// Input: stations[] = [1, 2, 3, 4, 5], k = 2
// Output: 1.00
// Explanation: Since all gaps are already equal (1 unit each), adding extra stations in between does not reduce the maximum distance.
// Input: stations[] = [3, 6, 12, 19, 33], k = 3
// Output: 6.00
// Explanation: The largest gap is 14 (between 19 and 33). Adding 2 stations there splits it into approx 4.67. The next largest gap is 7 (between 12 and 19). Adding 1 station splits it into 3.5. Now the maximum gap left is 6.
// Constraint:
// 1 ≤ stations.size() ≤ 105
// 0 ≤ stations[i] ≤ 106
// 0 ≤ k ≤ 105

// Approach: Using Binary Search
// Intuition
// We can use binary search to find the minimum possible value of d. The idea is to check if we can place k gas stations such that the maximum distance between adjacent gas stations is less than or equal to a certain value d. If we can, we try to find a smaller d; if we cannot, we need to increase d.
// Steps
// 1. Initialize low = 0 and high = max(stations[i+1] - stations[i]) for all i.
// 2. While high - low > 1e-6, do the following:
//    a. Set mid = (low + high) / 2.
//    b. Check if we can place k gas stations such that the maximum distance between adjacent gas stations is less than or equal to mid.
//    c. If we can, set high = mid; otherwise, set low = mid.
// 3. Return high as the answer, rounded to 6 decimal places.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &stations, int k, double mid)
    {
        int count = 0; // Count of additional gas stations needed
        for (int i = 1; i < stations.size(); i++)
        {
            // Calculate the distance between adjacent gas stations
            double distance = stations[i] - stations[i - 1];
            // Calculate how many additional gas stations are needed to ensure that the maximum distance is less than or equal to mid
            count += (int)(distance / mid);
        }
        return count <= k; // If we can place k or fewer gas stations, return true; otherwise, return false.
    }

    double minmaxGasDist(vector<int> &stations, int k)
    {
        // Finding the maximum distance between adjacent gas stations
        double low = 0, high = 0;

        // why high is initialized to the maximum distance between adjacent gas stations? Because we want to minimize the maximum distance, and the initial maximum distance is the worst-case scenario. We will use binary search to find a better (smaller) maximum distance by placing additional gas stations.
        for (int i = 1; i < stations.size(); i++)
        {
            high = max(high, (double)(stations[i] - stations[i - 1]));
        }

        // Using for loop instead of while loop to avoid precision issues with floating-point numbers. We will iterate a fixed number of times (100) to ensure that we get a sufficiently accurate result.
        for (int i = 0; i < 100; i++)
        {
            double mid = low + (high - low) / 2; // mid is the candidate maximum distance we are testing. We will check if we can place k gas stations such that the maximum distance between adjacent gas stations is less than or equal to mid.

            if (isPossible(stations, k, mid))
            {
                high = mid; // If it is possible to place k gas stations with maximum distance mid, we try to find a smaller maximum distance by setting high = mid.
            }
            else
            {
                low = mid; // If it is not possible, we need to increase the maximum distance by setting low = mid.
            }
        }
        return high;
    }
};