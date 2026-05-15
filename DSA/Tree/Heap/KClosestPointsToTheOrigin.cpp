// 973. K Closest Points to Origin
// Medium
// Topics
// premium lock icon
// Companies
// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

 

// Example 1:


// Input: points = [[1,3],[-2,2]], k = 1
// Output: [[-2,2]]
// Explanation:
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
// Example 2:

// Input: points = [[3,3],[5,-1],[-2,4]], k = 2
// Output: [[3,3],[-2,4]]
// Explanation: The answer [[-2,4],[3,3]] would also be accepted.
 

// Constraints:

// 1 <= k <= points.length <= 104
// -104 <= xi, yi <= 104


// approach 1: we can use a max heap to keep track of the k closest points to the origin. We can iterate through the points and calculate the distance of each point from the origin. If the size of the heap is less than k, we can simply add the point to the heap. If the size of the heap is equal to k, we can compare the distance of the current point with the distance of the point at the top of the heap (the farthest point in the heap). If the distance of the current point is less than the distance of the point at the top of the heap, we can remove the point at the top of the heap and add the current point to the heap. This way, we will always have the k closest points in the heap. The time complexity of this approach is O(nlogk) where n is the number of points and k is the number of closest points we want to return.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
            priority_queue<pair<double, vector<int>>> maxHeap; // max heap to keep track of the k closest points
            for (auto point : points) { // iterate through the points
                double distance = sqrt(pow(point[0], 2) + pow(point[1], 2)); // calculate the distance of the point from the origin
                if (maxHeap.size() < k) { // if the size of the heap is less than k, add the point to the heap
                    maxHeap.push({distance, point});
                } else { // if the size of the heap is equal to k, compare the distance of the current point with the distance of the point at the top of the heap
                    if (distance < maxHeap.top().first) { // if the distance of the current point is less than the distance of the point at the top of the heap, remove the point at the top of the heap and add the current point to the heap
                        maxHeap.pop();
                        maxHeap.push({distance, point});
                    }
                }
            }
            vector<vector<int>> result; // vector to store the k closest points
            while (!maxHeap.empty()) { // iterate through the heap and add the points to the result vector
                result.push_back(maxHeap.top().second);
                maxHeap.pop();
            }
            return result; // return the k closest points
        }
};