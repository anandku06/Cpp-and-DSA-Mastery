// 703. Kth Largest Element in a Stream
// Easy
// Topics
// premium lock icon
// Companies
// You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

// You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

// Implement the KthLargest class:

// KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
// int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.

// Example 1:

// Input:
// ["KthLargest", "add", "add", "add", "add", "add"]
// [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

// Output: [null, 4, 5, 5, 8, 8]

// Explanation:

// KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
// kthLargest.add(3); // return 4
// kthLargest.add(5); // return 5
// kthLargest.add(10); // return 5
// kthLargest.add(9); // return 8
// kthLargest.add(4); // return 8

// Example 2:

// Input:
// ["KthLargest", "add", "add", "add", "add"]
// [[4, [7, 7, 7, 7, 8, 3]], [2], [10], [9], [9]]

// Output: [null, 7, 7, 7, 8]

// Explanation:

// KthLargest kthLargest = new KthLargest(4, [7, 7, 7, 7, 8, 3]);
// kthLargest.add(2); // return 7
// kthLargest.add(10); // return 7
// kthLargest.add(9); // return 7
// kthLargest.add(9); // return 8

// Constraints:

// 0 <= nums.length <= 104
// 1 <= k <= nums.length + 1
// -104 <= nums[i] <= 104
// -104 <= val <= 104
// At most 104 calls will be made to add.

// approach: min heap, bcz we want to maintain the kth largest element at the top of the heap, so we can easily return it when needed. We will keep adding elements to the heap until we have k elements in it. Once we have k elements, we will compare the new element with the top of the heap (the kth largest element). If the new element is larger than the top of the heap, we will remove the top element and add the new element to the heap. This way, we will always have the kth largest element at the top of the heap.
// TC: O(nlogk) for constructor, O(logk) for add()

#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
public:
    int K;                                                  // variable to store the value of k
    priority_queue<int, vector<int>, greater<int>> minHeap; // min heap to store the k largest elements

    KthLargest(vector<int> &nums, int k)
    {
        K = k; // initialize the value of k

        for (int num : nums) // iterate through the input array of test scores
        {
            minHeap.push(num); // add the current test score to the min heap

            if (minHeap.size() > k) // if the size of the min heap exceeds k, remove the smallest element from the min heap
                minHeap.pop();
        }
    }

    int add(int val)
    {
        minHeap.push(val); // add the new test score to the min heap

        if (minHeap.size() > K) // if the size of the min heap exceeds k, remove the smallest element from the min heap
            minHeap.pop();

        return minHeap.top(); // return the kth largest element, which is now at the top of the min heap
    }
};
