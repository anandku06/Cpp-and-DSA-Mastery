// 85. Maximal Rectangle
// Hard
// Topics
// premium lock icon
// Companies
// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// Example 1:

// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:

// Input: matrix = [["0"]]
// Output: 0
// Example 3:

// Input: matrix = [["1"]]
// Output: 1

// Constraints:

// rows == matrix.length
// cols == matrix[i].length
// 1 <= rows, cols <= 200
// matrix[i][j] is '0' or '1'.

// approach: we can use the largest rectangle in histogram approach to solve this problem. We can treat each row of the matrix as a histogram and calculate the largest rectangle area for each row. We can keep track of the maximum area found so far and return it at the end. The time complexity of this approach is O(n*m) where n is the number of rows and m is the number of columns in the matrix.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;   // to store the indices of the bars
        int maxArea = 0; // to store the maximum area found so far

        heights.push_back(0); // add a bar of height 0 to the end of the histogram to pop all the bars from the stack at the end
        for (int i = 0; i < heights.size(); i++)
        {
            // Maintain a strictly increasing stack
            while (!st.empty() && heights[i] < heights[st.top()])
            {
                int height = heights[st.top()];
                st.pop();

                // If the stack is empty, this popped bar was the shortest so far,
                // meaning it can extend all the way back to the start (index 0).
                int width = st.empty() ? i : (i - st.top() - 1);

                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;

        int maxArea = 0;
        vector<int> heights(matrix[0].size(), 0);

        for (const auto &row : matrix)
        {
            for (int j = 0; j < row.size(); j++)
            {
                // Update the heights for the histogram
                heights[j] = row[j] == '1' ? heights[j] + 1 : 0;
            }
            // Calculate the largest rectangle area for the current histogram
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};