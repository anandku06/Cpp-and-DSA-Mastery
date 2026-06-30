// Buildings with Sunlight
// Difficulty: EasyAccuracy: 40.46%Submissions: 114K+Points: 2
// Given the array arr[] of heights of certain buildings that lie adjacent to each other, Sunlight starts falling from the left side of the buildings. If there is a building of a certain height, all the buildings to the right side of it having lesser heights cannot see the sun. Find the total number of buildings that receive sunlight.

// Note: Buildings with equal height do not block each other and can also receive sunlight.

// Examples:

// Input: arr[] = [6, 2, 8, 4, 11, 13]
// Output: 4
// Explanation: Only the buildings with heights 6, 8, 11, and 13 receive sunlight; therefore, the output is 4.

// Input: arr[] = [2, 5, 1, 8, 3]
// Output: 3
// Explanation: Only buildings of height 2, 5 and 8 can see the sun, hence output is 3.

// Input: arr[] = [3, 3, 3, 1]
// Output: 3
// Explanation: The first three buildings (height 3) receive sunlight, while the last building (1) is blocked. Hence, the output is 3.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 105

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countBuildingsWithSunlight(vector<int> &arr)
    {
        // Monotonic non-decreasing stack to store heights of buildings receiving sunlight
        stack<int> st;

        for (int height : arr)
        {
            // If stack is empty, the first building always gets sunlight
            // If current building is >= the tallest building found so far (st.top())
            if (st.empty() || height >= st.top())
            {
                st.push(height);
            }
            // Note: If height < st.top(), it is blocked, so we do nothing.
        }

        // The size of the stack represents the number of buildings that can see the sun
        return st.size();
    }
};

class Solution_2
{
public:
    int countBuildingsWithSunlight(vector<int> &arr)
    {
        int cnt = 1;

        int maxi = arr[0];

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] >= maxi)
            {
                cnt++;
                maxi = arr[i];
            }
        }

        return maxi;
    }
};