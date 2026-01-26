// 215. Kth Largest Element in an Array

// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Can you solve it without sorting?

 

// Example 1:

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5
// Example 2:

// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
// Output: 4

// approach_1 : using min-heap, maintaining a min-heap of size k and the top element of this heap will be our answer.
//              as min-heap will store the least element at the top and greatest element at the bottom and the size of the heap is k
//              this implies, the top element will be our answer

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int kthLargestElement(vector<int>& nums, int k) {
            // priority_queue<int> pq; // this is default a max-heap
            priority_queue<int, vector<int>, greater<int>> pq; // this is a min-heap

            for(auto i : nums) {
                pq.push(i);

                if(pq.size() > k) pq.pop();
            }

            return pq.top();
        }
};