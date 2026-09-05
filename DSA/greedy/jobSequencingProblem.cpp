// Job sequencing Problem
// Medium

// Hints
// Company
// Given an 2D array Jobs of size Nx3, where Jobs[i][0] represents JobID , Jobs[i][1] represents Deadline , Jobs[i][2] represents Profit associated with that job. Each Job takes 1 unit of time to complete and only one job can be scheduled at a time.

// The profit associated with a job is earned only if it is completed by its deadline. Find the number of jobs and maximum profit.

// Example 1

// Input : Jobs = [ [1, 4, 20] , [2, 1, 10] , [3, 1, 40] , [4, 1, 30] ]

// Output : 2 60

// Explanation : Job with JobID 3 can be performed at time t=1 giving a profit of 40.

// Job with JobID 1 can be performed at time t=2 giving a profit of 20.

// No more jobs can be scheduled, So total Profit = 40 + 20 => 60.

// Total number of jobs completed are two, JobID 1, JobID 3.

// So answer is 2 60.

// Example 2

// Input : Jobs = [ [1, 2, 100] , [2, 1, 19] , [3, 2, 27] , [4, 1, 25] , [5, 1, 15] ]

// Output : 2 127

// Explanation : Job with JobID 1 can be performed at time time t=1 giving a profit of 100.

// Job with JobID 3 can be performed at time t=2 giving a profit of 27.

// No more jobs can be scheduled, So total Profit = 100 + 27 => 127.

// Total number of jobs completed are two, JobID 1, JobID 3.

// So answer is 2 127.

// Now your turn!

// Input : Jobs = [ [1, 1, 100] , [2, 2, 200] , [3, 3, 300] , [4, 4, 400] ]

// Output:

// Pick your answer

// 3 1000

// 3 800

// 4 1000

// 4 800
// Constraints

// 1 <= N <= 104
// 1 <= Deadline <= N
// 1 <= Profit <= 500

// Approach: The problem can be solved using a greedy algorithm. We can sort the jobs in descending order of profit and then schedule the jobs one by one, starting from the job with the highest profit. For each job, we check if it can be scheduled before its deadline. If it can be scheduled, we add it to the list of scheduled jobs and update the total profit. Finally, we return the number of scheduled jobs and the total profit.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> jobScheduling(vector<vector<int>> &Jobs)
    {
        int n = Jobs.size(); // get the number of jobs

        sort(Jobs.begin(), Jobs.end(), [](const vector<int> &a, const vector<int> &b)
             {
                 return a[2] > b[2]; // sort in descending order of profit
             });

        int maxDeadline = 0; // initialize the maximum deadline
        for (int i = 0; i < n; i++)
        {
            maxDeadline = max(maxDeadline, Jobs[i][1]); // find the maximum deadline
        }

        vector<int> slot(maxDeadline + 1, -1); // create a slot array to keep track of scheduled jobs, initialized to -1 (no job scheduled)

        int cnt = 0;    // initialize the count of scheduled jobs
        int profit = 0; // initialize the total profit

        for (int i = 0; i < n; i++)
        {
            for (int j = Jobs[i][1]; j > 0; j--) // check for available slots from the job's deadline to 1
            {
                if (slot[j] == -1) // if the slot is available
                {
                    slot[j] = Jobs[i][0]; // schedule the job in the slot
                    cnt++;                // increment the count of scheduled jobs
                    profit += Jobs[i][2]; // add the profit of the job to the total profit
                    break;                // break the loop as we have scheduled the job
                }
            }
        }

        return {cnt, profit}; // return the count of scheduled jobs and the total profit
    }
};