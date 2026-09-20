// 907. Sum of Subarray Minimums
// Medium
// Topics
// premium lock icon
// Companies
// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

// Example 1:

// Input: arr = [3,1,2,4]
// Output: 17
// Explanation:
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Sum is 17.
// Example 2:

// Input: arr = [11,81,94,43,3]
// Output: 444

// Constraints:

// 1 <= arr.length <= 3 * 104
// 1 <= arr[i] <= 3 * 104

// approach: Using a Stack
// Intuition
// We can find the previous less element and the next less element for each element in the array. The previous less element is the first element to the left of the current element that is less than the current element. The next less element is the first element to the right of the current element that is less than the current element.
// The number of subarrays in which the current element is the minimum is equal to the product of the distance to the previous less element and the distance to the next less element. We can then multiply this count by the value of the current element to get its contribution to the sum of subarray minimums. Finally, we can sum up all contributions and return the result modulo 10^9 + 7.

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

class Solution
{
public:
    vector<int> getPreviousLess(vector<int> &arr)
    {
        int n = arr.size();      // size of the array
        vector<int> left(n, -1); // initialize the left array with -1
        stack<int> st;           // stack to keep track of the elements

        for (int i = 0; i < n; i++) // iterate through the array
        {
            while (!st.empty() && arr[st.top()] >= arr[i]) // pop elements from the stack until we find a less element
                st.pop();

            if (!st.empty()) // if the stack is not empty, the top element is the previous less element
                left[i] = st.top();

            st.push(i); // push the current index onto the stack
        }

        return left;
    }

    vector<int> getNextLess(vector<int> &arr)
    {
        int n = arr.size();      // size of the array
        vector<int> right(n, n); // initialize the right array with n
        stack<int> st;           // stack to keep track of the elements

        for (int i = n - 1; i >= 0; i--) // iterate through the array in reverse
        {
            while (!st.empty() && arr[st.top()] > arr[i]) // pop elements from the stack until we find a less element
                st.pop();

            if (!st.empty()) // if the stack is not empty, the top element is the next less element
                right[i] = st.top();

            st.push(i); // push the current index onto the stack
        }

        return right;
    }

    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();                      // size of the array
        vector<int> left = getPreviousLess(arr); // get the previous less element for each element
        vector<int> right = getNextLess(arr);    // get the next less element for each element

        long long ans = 0; // initialize the answer

        for (int i = 0; i < n; i++) // iterate through the array
        {
            long long count = (long long)(i - left[i]) * (right[i] - i); // calculate the number of subarrays in which the current element is the minimum
            ans = (ans + count * arr[i]) % MOD;                          // add the contribution of the current element to the answer
        }

        return ans; // return the answer
    }
};