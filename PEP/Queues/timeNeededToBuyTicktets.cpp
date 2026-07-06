// 2073. Time Needed to Buy Tickets
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.

// You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].

// Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.

// Return the time taken for the person initially at position k (0-indexed) to finish buying tickets.

// Example 1:

// Input: tickets = [2,3,2], k = 2

// Output: 6

// Explanation:

// The queue starts as [2,3,2], where the kth person is underlined.
// After the person at the front has bought a ticket, the queue becomes [3,2,1] at 1 second.
// Continuing this process, the queue becomes [2,1,2] at 2 seconds.
// Continuing this process, the queue becomes [1,2,1] at 3 seconds.
// Continuing this process, the queue becomes [2,1] at 4 seconds. Note: the person at the front left the queue.
// Continuing this process, the queue becomes [1,1] at 5 seconds.
// Continuing this process, the queue becomes [1] at 6 seconds. The kth person has bought all their tickets, so return 6.
// Example 2:

// Input: tickets = [5,1,1,1], k = 0

// Output: 8

// Explanation:

// The queue starts as [5,1,1,1], where the kth person is underlined.
// After the person at the front has bought a ticket, the queue becomes [1,1,1,4] at 1 second.
// Continuing this process for 3 seconds, the queue becomes [4] at 4 seconds.
// Continuing this process for 4 seconds, the queue becomes [] at 8 seconds. The kth person has bought all their tickets, so return 8.

// Constraints:

// n == tickets.length
// 1 <= n <= 100
// 1 <= tickets[i] <= 100
// 0 <= k < n

// approach: The problem can be solved by simulating the process of buying tickets. We can keep track of the time taken for the person at position k to finish buying tickets. We can iterate through the tickets array and for each person, we can decrement their ticket count by 1 and increment the time taken by 1. We can continue this process until the person at position k has bought all their tickets. Finally, we return the time taken.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int time = 0;           // to keep track of the time taken for the person at position k to finish buying tickets
        int n = tickets.size(); // get the size of the input array

        while (tickets[k] > 0) // continue until the person at position k has bought all their tickets
        {
            for (int i = 0; i < n; i++) // iterate through the tickets array
            {
                if (tickets[i] > 0) // if the current person has tickets left to buy
                {
                    tickets[i]--; // decrement their ticket count by 1
                    time++;       // increment the time taken by 1
                }
                if (tickets[k] == 0) // if the person at position k has bought all their tickets
                    break;           // break out of the loop
            }
        }

        return time; // return the time taken for the person at position k to finish buying tickets
    }
};

// Using Queue to solve the problem
class Queue_Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        queue<int> q; // create a queue to store the indices of the people in the line

        int time = 0; // to keep track of the time taken for the person at position k to finish buying tickets

        for (int i = 0; i < tickets.size(); i++) // iterate through the tickets array
        {
            q.push(i); // push the index of the current person into the queue
        }

        // continue until the person at position k has bought all their tickets
        while (!q.empty())
        {
            time++; // increment the time taken by 1

            int f = q.front(); // get the index of the person at the front of the queue
            q.pop();           // remove the person at the front of the queue

            tickets[f]--; // decrement their ticket count by 1

            if (f == k && tickets[f] == 0) // if the person at position k has bought all their tickets
                break;                     // break out of the loop

            if (tickets[f] > 0) // if the current person has tickets left to buy
            {
                q.push(f); // push their index back into the queue
            }
        }

        return time; // return the time taken for the person at position k to finish buying tickets
    }
};