// 1337. The K Weakest Rows in a Matrix
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

// A row i is weaker than a row j if one of the following is true:

// The number of soldiers in row i is less than the number of soldiers in row j.
// Both rows have the same number of soldiers and i < j.
// Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

// Example 1:

// Input: mat =
// [[1,1,0,0,0],
//  [1,1,1,1,0],
//  [1,0,0,0,0],
//  [1,1,0,0,0],
//  [1,1,1,1,1]],
// k = 3
// Output: [2,0,3]
// Explanation:
// The number of soldiers in each row is:
// - Row 0: 2
// - Row 1: 4
// - Row 2: 1
// - Row 3: 2
// - Row 4: 5
// The rows ordered from weakest to strongest are [2,0,3,1,4].
// Example 2:

// Input: mat =
// [[1,0,0,0],
//  [1,1,1,1],
//  [1,0,0,0],
//  [1,0,0,0]],
// k = 2
// Output: [0,2]
// Explanation:
// The number of soldiers in each row is:
// - Row 0: 1
// - Row 1: 4
// - Row 2: 1
// - Row 3: 1
// The rows ordered from weakest to strongest are [0,2,3,1].

// Constraints:

// m == mat.length
// n == mat[i].length
// 2 <= n, m <= 100
// 1 <= k <= m
// matrix[i][j] is either 0 or 1.

// approach: we can use a min heap to keep track of the k weakest rows in the matrix. We can iterate through the rows of the matrix and count the number of soldiers in each row. We can then push a pair of (number of soldiers, row index) into the min heap. If the size of the heap exceeds k, we can pop the top element from the heap. This way, we will always have the k weakest rows in the heap. The time complexity of this approach is O(m log k) where m is the number of rows in the matrix and k is the number of weakest rows we want to return.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int n = mat.size();    // number of rows
        int m = mat[0].size(); // number of columns

        // custom comparator for the max heap to compare the pairs based on the number of soldiers and row index
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b)
        {
            if (a.first == b.first) // if the number of soldiers is the same, compare the row index
            {
                return a.second < b.second; // return true if a's row index is less than b's row index
            }
            return a.first < b.first; // return true if a's number of soldiers is less than b's number of soldiers
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> maxHeap(cmp); // max heap to keep track of the

        for (int i = 0; i < n; i++)
        {
            // binary search to find the number of soldiers in the row
            int left = 0, right = m;

            // why not equal to right? because we want to find the first 0 in the row, so we will keep searching until left < right
            while (left < right)
            {
                int mid = left + (right - left) / 2;

                // if the mid element is 1, then we need to search in the right half of the row
                if (mat[i][mid] == 1)
                {
                    left = mid + 1;
                }
                // if the mid element is 0, then we need to search in the left half of the row, storing the index of the last 1 we found
                else
                {
                    right = mid;
                }
            }
            int cnt = left; // number of soldiers in the row

            maxHeap.push({cnt, i}); // push the pair (number of soldiers, row index) into the max heap

            if (maxHeap.size() > k) // if the size of the heap exceeds k, pop the top element from the heap
            {
                maxHeap.pop();
            }
        }

        vector<int> ans; // vector to store the k weakest rows
        while (!maxHeap.empty())
        {
            ans.push_back(maxHeap.top().second); // push the row index into the answer vector
            maxHeap.pop();
        }

        // reverse the answer vector to get the k weakest rows in the correct order
        reverse(ans.begin(), ans.end());

        return ans; // return the k weakest rows
    }
};