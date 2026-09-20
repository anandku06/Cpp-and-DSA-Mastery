// 735. Asteroid Collision
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.

// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

// Example 1:

// Input: asteroids = [5,10,-5]
// Output: [5,10]
// Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
// Example 2:

// Input: asteroids = [8,-8]
// Output: []
// Explanation: The 8 and -8 collide exploding each other.
// Example 3:

// Input: asteroids = [10,2,-5]
// Output: [10]
// Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
// Example 4:

// Input: asteroids = [3,5,-6,2,-1,4]​​​​​​​
// Output: [-6,2,4]
// Explanation: The asteroid -6 makes the asteroid 3 and 5 explode, and then continues going left. On the other side, the asteroid 2 destroys -1. Since 2 and 4 are both moving right, they never collide.

// Constraints:

// 2 <= asteroids.length <= 104
// -1000 <= asteroids[i] <= 1000
// asteroids[i] != 0

// approach: Using a Stack
// Intuition
// We can use a stack to keep track of the asteroids that are still in play. We will iterate through the asteroids array and for each asteroid, we will check if it is moving to the right (positive) or to the left (negative). If it is moving to the right, we will push it onto the stack. If it is moving to the left, we will check if there are any asteroids in the stack that are moving to the right. If there are, we will compare their sizes and determine which one explodes. If the asteroid in the stack is larger, we will pop it from the stack and continue checking for collisions. If the asteroid in the stack is smaller, we will pop it from the stack and continue checking for collisions. If they are equal in size, we will pop both asteroids from the stack and continue checking for collisions. If there are no asteroids in the stack that are moving to the right, we will push the current asteroid onto the stack.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st; // stack to keep track of the asteroids

        for (int &a : asteroids) // iterate through the asteroids
        {
            if (a != 0)
                st.push(a); // push the asteroid onto the stack if it is not 0

            while (!st.empty() && st.top() > 0 && a < 0) // check for collisions
            {
                int sum = st.top() + a; // calculate the sum of the two asteroids

                if (sum < 0)
                {
                    st.pop(); // the asteroid in the stack explodes
                }
                else if (sum > 0)
                {
                    a = 0; // the current asteroid explodes
                }
                else
                {
                    st.pop(); // both asteroids explode
                    a = 0;    // the current asteroid explodes
                }
            }
        }
        int n = st.size(); // get the size of the stack
        int i = n - 1;     // initialize the index for the result array

        vector<int> result(n); // initialize the result array with the size of the stack

        while (!st.empty())
        {
            result[i--] = st.top(); // add the asteroid to the result array
            st.pop();
        }

        return result;
    }
};