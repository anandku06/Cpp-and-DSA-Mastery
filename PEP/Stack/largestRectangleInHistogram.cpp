// 84. Largest Rectangle in Histogram
// Hard
// Topics
// premium lock icon
// Companies
// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// Example 1:

// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
// Example 2:

// Input: heights = [2,4]
// Output: 4

// Constraints:

// 1 <= heights.length <= 105
// 0 <= heights[i] <= 104

// approach: brute force
// Intuition
// For every bar, I need Previous Smaller Element and Next Smaller Element, then I can calculate the area of the rectangle formed by the current bar and the bars at the indices of the Previous Smaller Element and Next Smaller Element. The area will be equal to the height of the current bar multiplied by the width of the rectangle, which is equal to the difference between the indices of the Next Smaller Element and Previous Smaller Element minus 1. We will keep track of the maximum area found so far and return it at the end. The time complexity of this approach is O(n) where n is the number of bars in the histogram.

#include <bits/stdc++.h>
using namespace std;

class BruteForceSolution
{
public:
    vector<int> nextSmallerElement(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st; // to store the indices of the bars

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top(); // if stack is empty, then there is no smaller element to the right, so we can consider the index as n
            st.push(i);                         // push the current index onto the stack
        }
        return ans;
    }

    vector<int> previousSmallerElement(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st; // to store the indices of the bars

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top(); // if stack is empty, then there is no smaller element to the left, so we can consider the index as -1
            st.push(i);                          // push the current index onto the stack
        }
        return ans;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> nextSmaller = nextSmallerElement(heights);
        vector<int> previousSmaller = previousSmallerElement(heights);

        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            int height = heights[i];
            int width = nextSmaller[i] - previousSmaller[i] - 1; // width of the rectangle formed by the current bar and the bars at the indices of the Previous Smaller Element and Next Smaller Element
            int area = height * width;                           // area of the rectangle
            maxArea = max(maxArea, area);                        // update the maximum area found so far
        }
        return maxArea;
    }
};

// approach: using stack
// Intuition


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the largest rectangle area
    int largestRectangleArea(vector<int> &heights)
    {

        int n = heights.size(); // Size of array

        // Stack
        stack<int> st;

        // To store largest area
        int largestArea = 0;

        // To store current area
        int area;

        /* To store the indices of next
        and previous smaller elements */
        int nse, pse;

        // Traverse on the array
        for (int i = 0; i < n; i++)
        {

            /* Pop the elements in the stack until
            the stack is not empty and the top
            elements is not the smaller element */
            while (!st.empty() &&
                   heights[st.top()] >= heights[i])
            {

                // Get the index of top of stack
                int ind = st.top();
                st.pop();

                /* Update the index of
                previous smaller element */
                pse = st.empty() ? -1 : st.top();

                /* Next smaller element index for
                the popped element is current index */
                nse = i;

                // Calculate the area of the popped element
                area = heights[ind] * (nse - pse - 1);

                // Update the maximum area
                largestArea = max(largestArea, area);
            }

            // Push the current index in stack
            st.push(i);
        }

        // For elements that are not popped from stack
        while (!st.empty())
        {

            // NSE for such elements is size of array
            nse = n;

            // Get the index of top of stack
            int ind = st.top();
            st.pop();

            // Update the previous smaller element
            pse = st.empty() ? -1 : st.top();

            // Calculate the area of the popped element
            area = heights[ind] * (nse - pse - 1);

            // Update the maximum area
            largestArea = max(largestArea, area);
        }

        // Return largest area found
        return largestArea;
    }
};