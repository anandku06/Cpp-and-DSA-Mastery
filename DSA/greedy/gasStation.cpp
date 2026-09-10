// 134. Gas Station
// Medium
// Topics
// premium lock icon
// Companies
// There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

// Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.

// Example 1:

// Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
// Output: 3
// Explanation:
// Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
// Travel to station 4. Your tank = 4 - 1 + 5 = 8
// Travel to station 0. Your tank = 8 - 2 + 1 = 7
// Travel to station 1. Your tank = 7 - 3 + 2 = 6
// Travel to station 2. Your tank = 6 - 4 + 3 = 5
// Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
// Therefore, return 3 as the starting index.
// Example 2:

// Input: gas = [2,3,4], cost = [3,4,3]
// Output: -1
// Explanation:
// You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
// Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
// Travel to station 0. Your tank = 4 - 3 + 2 = 3
// Travel to station 1. Your tank = 3 - 3 + 3 = 3
// You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
// Therefore, you can't travel around the circuit once no matter where you start.

// Constraints:

// n == gas.length == cost.length
// 1 <= n <= 105
// 0 <= gas[i], cost[i] <= 104
// The input is generated such that the answer is unique.

// approach : We can solve this problem using a greedy approach. We can keep track of the total gas and total cost. If the total gas is less than the total cost, then we cannot travel around the circuit once. If the total gas is greater than or equal to the total cost, then we can travel around the circuit once. We can keep track of the current gas and current cost. If the current gas is less than the current cost, then we cannot travel to the next station. We can reset the starting station to the next station and reset the current gas and current cost to 0. We can continue this process until we have traversed all the stations.

// brute-force : We can try to start from each station and check if we can travel around the circuit once. If we can travel around the circuit once, then we can return the starting station's index. If we cannot travel around the circuit once, then we can return -1. The time complexity of this approach is O(n^2).

#include <bits/stdc++.h>
using namespace std;

// brute-force approach
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size(); // number of gas stations

        for (int i = 0; i < n; i++) // try to start from each station
        {
            if (gas[i] < cost[i]) // if the gas at the station is less than the cost to travel to the next station, then we cannot start from this station
                continue;

            int j = (i + 1) % n; // next station

            int currGas = gas[i] - cost[i] + gas[j]; // gas after traveling to the next station

            while (j != i)
            {
                if (currGas < cost[j]) // if the current gas is less than the cost to travel to the next station, then we cannot travel to the next station
                    break;

                int costOfCurrentStation = cost[j]; // cost to travel to the next station
                j = (j + 1) % n;                    // next station
                int gasAtNextStation = gas[j];      // gas at the next station

                currGas = currGas - costOfCurrentStation + gasAtNextStation; // gas after traveling to the next station
            }

            if (i == j)   // if we have traversed all the stations and we are back to the starting station, then we can travel around the circuit once
                return i; // return the starting station's index
        }

        return -1; // if we cannot travel around the circuit once, then we can return -1
    }
};

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int totalGas = 0, totalCost = 0;
        int currentGas = 0, startStation = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += gas[i] - cost[i];

            // If current gas is less than 0, we cannot travel to the next station
            if (currentGas < 0)
            {
                // Reset the starting station to the next station
                startStation = i + 1;
                currentGas = 0; // Reset current gas
            }
        }

        // If total gas is less than total cost, we cannot travel around the circuit once
        return (totalGas >= totalCost) ? startStation : -1;
    }
};
