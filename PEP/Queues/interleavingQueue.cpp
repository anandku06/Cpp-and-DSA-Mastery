// Interleave the First Half of the Queue with Second Half
// Difficulty: MediumAccuracy: 62.41%Submissions: 31K+Points: 4Average Time: 20m
// Given a queue q[] of even size. Your task is to rearrange the queue by interleaving its first half with the second half.

// Interleaving is the process of mixing two sequences by alternating their elements while preserving their relative order.
// In other words, Interleaving means place the first element from the first half and then first element from the 2nd half and again second element from the first half and then second element from the 2nd half and so on....

// Examples:

// Input: q[] = [2, 4, 3, 1]
// Output: [2, 3, 4, 1]
// Explanation: We place the first element of the first half 2 and after that
// place the first element of second half 3 and after that repeat
// the same process one more time so the resulting queue will be [2, 3, 4, 1]
// Input: q[] = [3, 5]
// Output: [3, 5]
// Explanation: We place the first element of the first half 3 and first element
// of the second half 5 so the resulting queue is [3, 5]
// Constraints:
// 1 ≤ queue.size() ≤ 103
// 1 ≤ queue[i] ≤ 105

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rearrangeQueue(queue<int> &q)
    {
        int n = q.size();
        int halfSize = n / 2;
        queue<int> first_half;

        // Step 1: Push the first half of elements into the auxiliary queue
        for (int i = 0; i < halfSize; i++)
        {
            first_half.push(q.front());
            q.pop();
        }

        // Step 2: Interleave the elements back into the original queue
        while (!first_half.empty())
        {
            // Fetch and push from the first half
            q.push(first_half.front());
            first_half.pop();

            // Fetch and push from the second half (currently at the front of q)
            q.push(q.front());
            q.pop();
        }
    }
};