// 2187. Minimum Time to Complete Trips
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.

// Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.

// You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. Return the minimum time required for all buses to complete at least totalTrips trips.

// Example 1:

// Input: time = [1,2,3], totalTrips = 5
// Output: 3
// Explanation:
// - At time t = 1, the number of trips completed by each bus are [1,0,0].
//   The total number of trips completed is 1 + 0 + 0 = 1.
// - At time t = 2, the number of trips completed by each bus are [2,1,0].
//   The total number of trips completed is 2 + 1 + 0 = 3.
// - At time t = 3, the number of trips completed by each bus are [3,1,1].
//   The total number of trips completed is 3 + 1 + 1 = 5.
// So the minimum time needed for all buses to complete at least 5 trips is 3.
// Example 2:

// Input: time = [2], totalTrips = 1
// Output: 2
// Explanation:
// There is only one bus, and it will complete its first trip at t = 2.
// So the minimum time needed to complete 1 trip is 2.

// Constraints:

// 1 <= time.length <= 105
// 1 <= time[i], totalTrips <= 107

// approach: Using Binary Search
// Intuition
// We can use binary search to find the minimum time required for all buses to complete at least totalTrips trips. The minimum possible time is 1 (if the fastest bus takes 1 unit of time and we only need 1 trip) and the maximum possible time is the maximum time taken by any bus multiplied by totalTrips (if we only have one bus and it has to complete all trips). We will initialize left to 1 and right to the maximum time taken by any bus multiplied by totalTrips. We will calculate the mid value and check if all buses can complete at least totalTrips trips within that time. If they can, we will move the right pointer to mid; otherwise, we will move the left pointer to mid + 1. We will continue this process until left is less than right, at which point left will be the minimum time required for all buses to complete at least totalTrips trips.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Helper function to check if all buses can complete at least totalTrips trips within time t
    bool possible(vector<int> &time, int totalTrips, long long t)
    {
        long long trips = 0; // to count the total number of trips completed by all buses within time t

        for (int i = 0; i < time.size(); i++)
        {
            trips += t / time[i]; // calculate the number of trips completed by the ith bus within time t and add it to the total trips

            if(trips >= totalTrips) // if the total number of trips completed is already greater than or equal to totalTrips, we can return true
                return true;
        }

        return false; // if the total number of trips completed is less than totalTrips, we return false
    }

    long long minimumTime(vector<int> &time, int totalTrips)
    {
        long long left = 1;                                                               // minimum time is 1 unit of time
        long long right = (long long)*min_element(time.begin(), time.end()) * totalTrips; // right is the maximum time taken by any bus multiplied by totalTrips

        while (left < right)
        {
            long long mid = left + (right - left) / 2; // calculate the mid value

            if (possible(time, totalTrips, mid))
                right = mid; // if all buses can complete at least totalTrips trips within mid time, move the right pointer to mid
            else
                left = mid + 1; // otherwise, move the left pointer to mid + 1
        }

        return left; // left will be the minimum time required for all buses to complete at least totalTrips trips
    }
};