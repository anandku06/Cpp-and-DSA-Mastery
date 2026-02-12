// 54. Spiral Matrix

// Given an m x n matrix, return all elements of the matrix in spiral order.

 
// Example 1:


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:


// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

// Intuition
// This problem asks us to traverse a matrix in spiral order: right → down → left → up, then repeat for inner layers. We need to maintain four boundaries (top, bottom, left, right) and shrink them inward after processing each side. The key is handling edge cases where rows or columns are exhausted before completing a full spiral layer.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> spiralMatrix(vector<vector<int>>& matrix) {
            int left = 0, right = matrix[0].size(), top = 0, bottom = matrix.size();
            vector<int> spiral;

            while (left <= right && top <= bottom)
            {
                for(int i = left; i <= right; i++) {
                    spiral.push_back(matrix[top][i]);
                }
                top++;

                for(int j = top; j <= bottom; j++) {
                    spiral.push_back(matrix[j][right]);
                }
                right--;

                if(top <= bottom) {
                    for(int k = right; k >= left; k--) {
                        spiral.push_back(matrix[bottom][k]);
                    }

                    bottom--;
                }

                if(left <= right) {
                    for(int l = bottom; l >= top; l--) {
                        spiral.push_back(matrix[l][left]);
                    }

                    left++;
                }
            }
            
            return spiral;
        }
};