// 739. Daily Temperatures
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
// Example 2:

// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]
// Example 3:

// Input: temperatures = [30,60,90]
// Output: [1,1,0]

// Constraints:

// 1 <= temperatures.length <= 105
// 30 <= temperatures[i] <= 100

// approach: The problem can be solved using a stack. We can iterate through the temperatures and for each temperature, we can check if it is greater than the temperature at the top of the stack. If it is, we can pop the top of the stack and update the answer for that index. We can continue this process until the stack is empty or the current temperature is less than or equal to the temperature at the top of the stack. Finally, we can push the current index onto the stack. This way, we can keep track of the indices of the temperatures that we have seen so far and update the answer accordingly.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // stack to store the indices of the temperatures
    stack<int> st;

    vector<int> dailyTemperature(vector<int> &temperatures)
    {
        // size of the input array
        int n = temperatures.size();
        vector<int> ans(n, 0);

        // iterate through the temperatures
        for (int i = 0; i < n; i++)
        {
            // if the stack is empty, push the current index onto the stack
            if (st.empty())
            {
                st.push(i);
                continue;
            }

            // while the stack is not empty and the current temperature is greater than the temperature at the top of the stack, pop the top of the stack and update the answer for that index
            while (!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                // update the answer for the index at the top of the stack
                ans[st.top()] = i - st.top();
                st.pop();
            }

            // push the current index onto the stack
            st.push(i);
        }

        return ans;
    }
};