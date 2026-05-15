// 295. Find Median from Data Stream
// Hard
// Topics
// premium lock icon
// Companies
// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

// Example 1:

// Input
// ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
// [[], [1], [2], [], [3], []]
// Output
// [null, null, null, 1.5, null, 2.0]

// Explanation
// MedianFinder medianFinder = new MedianFinder();
// medianFinder.addNum(1);    // arr = [1]
// medianFinder.addNum(2);    // arr = [1, 2]
// medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
// medianFinder.addNum(3);    // arr[1, 2, 3]
// medianFinder.findMedian(); // return 2.0

// Constraints:

// -105 <= num <= 105
// There will be at least one element in the data structure before calling findMedian.
// At most 5 * 104 calls will be made to addNum and findMedian.

// Follow up:

// If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
// If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?

// approach: We can use two heaps to store the smaller half and the larger half of the numbers. The max heap will store the smaller half of the numbers and the min heap will store the larger half of the numbers. We can then use the size of the heaps to determine how to add a new number and how to find the median.

#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
    priority_queue<int> LmaxHeap;                            // for storing the smaller half of the numbers
    priority_queue<int, vector<int>, greater<int>> RminHeap; // for storing the larger half of the numbers

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        // if the left max heap is empty or the number is less than or equal to the top of the left max heap, we add the number to the left max heap. Otherwise, we add the number to the right min heap.
        if (LmaxHeap.empty() || num <= LmaxHeap.top())
        {
            LmaxHeap.push(num);
        }
        else
        {
            RminHeap.push(num);
        }

        // if the size of the left max heap is greater than the size of the right min heap by more than 1, we need to move the top of the left max heap to the right min heap. If the size of the right min heap is greater than the size of the left max heap by more than 1, we need to move the top of the right min heap to the left max heap.
        if (LmaxHeap.size() > RminHeap.size() + 1)
        {
            RminHeap.push(LmaxHeap.top());
            LmaxHeap.pop();
        }
        else if (LmaxHeap.size() < RminHeap.size())
        {
            LmaxHeap.push(RminHeap.top());
            RminHeap.pop();
        }
    }

    double findMedian()
    {
        // if the size of the left max heap is greater than the size of the right min heap, we return the top of the left max heap. If the size of the right min heap is greater than the size of the left max heap, we return the top of the right min heap. If the size of both heaps is equal, we return the average of the tops of both heaps.
        if (LmaxHeap.size() > RminHeap.size())
        {
            return LmaxHeap.top();
        }
        else
        {
            return (LmaxHeap.top() + RminHeap.top()) / 2.0;
        }
    }
};