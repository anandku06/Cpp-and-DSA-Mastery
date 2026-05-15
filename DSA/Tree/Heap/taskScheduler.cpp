// 621. Task Scheduler
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

// Return the minimum number of CPU intervals required to complete all tasks.

// Example 1:

// Input: tasks = ["A","A","A","B","B","B"], n = 2

// Output: 8

// Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

// After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

// Example 2:

// Input: tasks = ["A","C","A","B","D","B"], n = 1

// Output: 6

// Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.

// With a cooling interval of 1, you can repeat a task after just one other task.

// Example 3:

// Input: tasks = ["A","A","A", "B","B","B"], n = 3

// Output: 10

// Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.

// There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.

// Constraints:

// 1 <= tasks.length <= 104
// tasks[i] is an uppercase English letter.
// 0 <= n <= 100

// approach 1: we can use a max heap to keep track of the tasks and their frequencies. We can iterate through the tasks and add them to the heap. We can also keep track of the number of intervals we have used. We can then pop the top k elements from the heap (where k is the number of tasks we can execute in one interval) and add them to the result. We can also decrease the frequency of the tasks and if the frequency becomes zero, we can remove it from the heap. We can repeat this process until the heap is empty. The time complexity of this approach is O(nlogn) where n is the number of tasks.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> freq; // map to store the frequency of each task
        for (char task : tasks)
        { // iterate through the tasks and count the frequency of each task
            freq[task]++;
        }
        priority_queue<int> maxHeap; // max heap to keep track of the tasks and their frequencies
        for (auto it : freq)
        { // iterate through the frequency map and add the frequencies to the heap
            maxHeap.push(it.second);
        }
        int intervals = 0; // variable to keep track of the number of intervals used
        while (!maxHeap.empty())
        {                     // repeat until the heap is empty
            vector<int> temp; // vector to store the tasks that we can execute in one interval
            for (int i = 0; i <= n; i++)
            { // iterate through the number of tasks we can execute in one interval
                if (!maxHeap.empty())
                { // if the heap is not empty, pop the top element and add it to the temp vector
                    temp.push_back(maxHeap.top());
                    maxHeap.pop();
                }
            }
            for (int i : temp)
            { // iterate through the temp vector and decrease the frequency of the tasks
                if (--i > 0)
                { // if the frequency becomes zero, we can remove it from the heap
                    maxHeap.push(i);
                }
            }
            intervals += !maxHeap.empty() ? n + 1 : temp.size(); // if the heap is not empty, we need to add n + 1 intervals, otherwise we can just add the size of the temp vector
        }
        return intervals; // return the number of intervals used
    }
};