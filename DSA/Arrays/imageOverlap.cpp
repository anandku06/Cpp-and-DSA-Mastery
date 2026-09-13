// 835. Image Overlap
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// You are given two images, img1 and img2, represented as binary, square matrices of size n x n. A binary matrix has only 0s and 1s as values.

// We translate one image however we choose by sliding all the 1 bits left, right, up, and/or down any number of units. We then place it on top of the other image. We can then calculate the overlap by counting the number of positions that have a 1 in both images.

// Note also that a translation does not include any kind of rotation. Any 1 bits that are translated outside of the matrix borders are erased.

// Return the largest possible overlap.

// Example 1:

// Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
// Output: 3
// Explanation: We translate img1 to right by 1 unit and down by 1 unit.

// The number of positions that have a 1 in both images is 3 (shown in red).

// Example 2:

// Input: img1 = [[1]], img2 = [[1]]
// Output: 1
// Example 3:

// Input: img1 = [[0]], img2 = [[0]]
// Output: 0

// Constraints:

// n == img1.length == img1[i].length
// n == img2.length == img2[i].length
// 1 <= n <= 30
// img1[i][j] is either 0 or 1.
// img2[i][j] is either 0 or 1.

// Approach: Brute Force
// Intuition
// We can solve this problem using a brute force approach. We can iterate through all possible translations of img1 and calculate the overlap with img2 for each translation. We can keep track of the maximum overlap found during the iterations.

// Concept of offset
// The offset represents the shift in position between the two images. For example, if we shift img1 one unit to the right and one unit down, the offset would be (1, 1).
// Offset ranges from -n+1 to n-1 for both x and y directions, where n is the size of the images. This is because we can shift img1 completely out of the bounds of img2 in either direction.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2, int rowOff, int colOff)
    {
        int n = img1.size(); // size of the images

        int cnt = 0; // to count the overlap for the current offset

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // calculate the new position of the pixel in img1 after applying the offset
                int newRow = i + rowOff;
                int newCol = j + colOff;

                if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= n)
                {
                    continue; // skip if the new position is out of bounds
                }

                // check if both img1 and img2 have a 1 at the new position
                if (img1[i][j] == 1 && img2[newRow][newCol] == 1)
                {
                    cnt++; // increment the count if there is an overlap
                }
            }
        }

        return cnt; // return the count of overlaps for the current offset
    }

    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {
        int n = img1.size(); // size of the images
        int maxOverlap = 0;  // to store the maximum overlap found

        // iterate through all possible offsets
        for (int rowOff = -n + 1; rowOff < n; rowOff++)
        {
            for (int colOff = -n + 1; colOff < n; colOff++)
            {
                int cnt = countOverlap(img1, img2, rowOff, colOff); // to count the overlap for the current offset
                maxOverlap = max(maxOverlap, cnt);
            }
        }

        return maxOverlap;
    }
};