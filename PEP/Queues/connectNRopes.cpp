// Minimum Cost of ropes
// Difficulty: MediumAccuracy: 42.73%Submissions: 283K+Points: 4
// Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths.

// Examples:

// Input: arr[] = [4, 3, 2, 6]
// Output: 29
// Explanation: First connect 2 and 3 to get [4, 5, 6] with a cost of 5, then connect 4 and 5 to get [9, 6] with a cost of 9, and finally connect 9 and 6 to get one rope with a cost of 15, giving a total minimum cost of 29. Any other order, such as connecting 4 and 6 first, results in a higher total cost of 38.
// Input: arr[] = [4, 2, 7, 6, 9]
// Output: 62
// Explanation: First, connect ropes 4 and 2, which makes the array [6, 7, 6, 9]. Cost of this operation 4 + 2 = 6. Next, add ropes 6 and 6, which results in [12, 7, 9]. Cost of this operation 6 + 6 = 12. Then, add 7 and 9, which makes the array [12,16]. Cost of this operation 7 + 9 = 16. And finally, add these two which gives [28]. Hence, the total cost is 6 + 12 + 16 + 28 = 62.
// Input: arr[] = [10]
// Output: 0
// Explanation: Since there is only one rope, no connections are needed, so the cost is 0.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 104

// approach: using a min-heap (priority queue) to always connect the two smallest ropes first, which ensures the minimum total cost. The time complexity of this approach is O(n log n) where n is the number of ropes.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(vector<int> &arr)
    {
        // Create a min-heap (priority queue) to store the lengths of the ropes
        priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());

        // Initialize the total cost to 0
        int totalCost = 0;

        // While there is more than one rope in the heap
        while (minHeap.size() > 1)
        {
            // Extract the two smallest ropes
            int first = minHeap.top();
            minHeap.pop();
            int second = minHeap.top();
            minHeap.pop();

            // Calculate the cost of connecting these two ropes
            int cost = first + second;

            // Add the cost to the total cost
            totalCost += cost;

            // Push the new rope back into the min-heap
            minHeap.push(cost);
        }

        // Return the total cost of connecting all ropes
        return totalCost;
    }
};

/**
 * Why pq.size() > 1?
 *  We continue the process until there is only one rope left in the priority queue. When there is only one rope left, it means all ropes have been connected into a single rope, and we have calculated the total cost of connecting them. Therefore, we stop the process when pq.size() > 1.
 */