// 853. Car Fleet
// Medium
// Topics
// premium lock icon
// Companies
// There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.

// You are given two integer arrays position and speed, both of length n, where position[i] is the starting mile of the ith car and speed[i] is the speed of the ith car in miles per hour.

// A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.

// A car fleet is a single car or a group of cars driving next to each other. The speed of the car fleet is the minimum speed of any car in the fleet.

// If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.

// Return the number of car fleets that will arrive at the destination.

// Example 1:

// Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]

// Output: 3

// Explanation:

// The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting each other at 12. The fleet forms at target.
// The car starting at 0 (speed 1) does not catch up to any other car, so it is a fleet by itself.
// The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.
// Example 2:

// Input: target = 10, position = [3], speed = [3]

// Output: 1

// Explanation:

// There is only one car, hence there is only one fleet.
// Example 3:

// Input: target = 100, position = [0,2,4], speed = [4,2,1]

// Output: 1

// Explanation:

// The cars starting at 0 (speed 4) and 2 (speed 2) become a fleet, meeting each other at 4. The car starting at 4 (speed 1) travels to 5.
// Then, the fleet at 4 (speed 2) and the car at position 5 (speed 1) become one fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.

// Constraints:

// n == position.length == speed.length
// 1 <= n <= 105
// 0 < target <= 106
// 0 <= position[i] < target
// All the values of position are unique.
// 0 < speed[i] <= 106

// approach: Using a Stack
// Intuition
// make a vector of pairs to store the position and speed of each car, then sort the vector based on the position in descending order, then iterate through the sorted vector and calculate the time it takes for each car to reach the target, if the stack is empty or the time of the current car is less than the time of the car at the top of the stack, then we push the time of the current car onto the stack, at the end, the number of fleets will be equal to the size of the stack.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();
        vector<pair<int, int>> cars(n); // to store the position and speed of each car

        // storing the position and speed of each car in a vector of pairs
        for (int i = 0; i < n; i++)
        {
            cars[i] = {position[i], speed[i]};
        }

        // sorting the cars based on their position in descending order
        sort(cars.rbegin(), cars.rend()); // why sorting in reverse order? because we want to iterate through the cars from the car closest to the target to the car farthest from the target

        stack<double> st; // to keep track of the time it takes for each car to reach the target
        for (int i = 0; i < n; i++)
        {
            // calculating the time it takes for the current car to reach the target
            double time = (double)(target - cars[i].first) / cars[i].second;

            // if the stack is empty or the time of the current car is less than the time of the car at the top of the stack, then we push the time of the current car onto the stack
            if (st.empty() && time > st.top())
                st.push(time);
        }

        return st.size(); // the number of fleets will be equal to the size of the stack at the end
    }
};

// without using stack