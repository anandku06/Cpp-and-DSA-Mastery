// Shortest Job first
// Difficulty: MediumAccuracy: 68.79%Submissions: 55K+Points: 4Average Time: 30m
// The shortest job first (SJF) or shortest job next, is a scheduling policy that selects the waiting process with the smallest execution time to execute next. Given an array of integers bt[] of size n. Array bt[] denotes the burst time of each process. Calculate the average waiting time of all the processes and return the nearest integer which is smaller or equal to the output.

// Note: Consider all process are available at time 0.

// Examples:

// Input: bt[] = [4,3,7,1,2]
// Output: 4
// Explanation: After sorting burst times by shortest job policy, calculated average waiting time is 4.
// Input: bt[] = [1,2,3,4]
// Output: 2
// Explanation: After sorting burst times by shortest job policy, calculated average waiting time is 2.
// Constraints:
// 1 <= n <= 105
// 1 <= arr[i] <= 105

// approach: The problem can be solved using a greedy algorithm. We can sort the burst times in ascending order and then calculate the waiting time for each process. The waiting time for a process is the sum of the burst times of all previous processes. Finally, we can calculate the average waiting time by dividing the total waiting time by the number of processes.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long averageWaitingTime(int bt[], int n)
    {
        sort(bt, bt + n); // sort the burst times in ascending order

        long long totalWaitingTime = 0; // initialize total waiting time
        long long waitingTime = 0;      // initialize waiting time for each process

        for (int i = 0; i < n; i++)
        {
            totalWaitingTime += waitingTime; // add the waiting time of the current process to the total waiting time
            waitingTime += bt[i];            // update the waiting time for the next process
        }

        return totalWaitingTime / n; // return the average waiting time
    }
};