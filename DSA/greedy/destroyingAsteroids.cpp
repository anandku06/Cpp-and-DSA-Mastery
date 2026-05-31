// 2126. Destroying Asteroids
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer mass, which represents the original mass of a planet. You are further given an integer array asteroids, where asteroids[i] is the mass of the ith asteroid.

// You can arrange for the planet to collide with the asteroids in any arbitrary order. If the mass of the planet is greater than or equal to the mass of the asteroid, the asteroid is destroyed and the planet gains the mass of the asteroid. Otherwise, the planet is destroyed.

// Return true if all asteroids can be destroyed. Otherwise, return false.

// Example 1:

// Input: mass = 10, asteroids = [3,9,19,5,21]
// Output: true
// Explanation: One way to order the asteroids is [9,19,5,3,21]:
// - The planet collides with the asteroid with a mass of 9. New planet mass: 10 + 9 = 19
// - The planet collides with the asteroid with a mass of 19. New planet mass: 19 + 19 = 38
// - The planet collides with the asteroid with a mass of 5. New planet mass: 38 + 5 = 43
// - The planet collides with the asteroid with a mass of 3. New planet mass: 43 + 3 = 46
// - The planet collides with the asteroid with a mass of 21. New planet mass: 46 + 21 = 67
// All asteroids are destroyed.
// Example 2:

// Input: mass = 5, asteroids = [4,9,23,4]
// Output: false
// Explanation:
// The planet cannot ever gain enough mass to destroy the asteroid with a mass of 23.
// After the planet destroys the other asteroids, it will have a mass of 5 + 4 + 9 + 4 = 22.
// This is less than 23, so a collision would not destroy the last asteroid.

// Constraints:

// 1 <= mass <= 105
// 1 <= asteroids.length <= 105
// 1 <= asteroids[i] <= 105

// approach: we can sort the asteroids in ascending order and then iterate through the sorted array. If the mass of the planet is greater than or equal to the mass of the asteroid, we can destroy the asteroid and add its mass to the planet. Otherwise, we return false.

// Is this problem similar to Last Stone Weight? Yes, it is similar to Last Stone Weight. In Last Stone Weight, we are given an array of stones and we can smash two stones together. If the stones have the same weight, both stones are destroyed. If the stones have different weights, the lighter stone is destroyed and the heavier stone's weight is reduced by the lighter stone's weight. We need to return the weight of the last remaining stone. In this problem, we are given an array of asteroids and we can collide the planet with the asteroids. If the mass of the planet is greater than or equal to the mass of the asteroid, the asteroid is destroyed and the planet gains the mass of the asteroid. Otherwise, the planet is destroyed. We need to return true if all asteroids can be destroyed, otherwise return false.

// So this problem we can use heap to get the heaviest asteroid and then check if the planet can destroy it. If it can, we add the mass of the asteroid to the planet and continue. If it cannot, we return false.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        sort(asteroids.begin(), asteroids.end());
        // long long currMass = mass; // use long long to avoid overflow
        for (int i = 0; i < asteroids.size(); i++)
        {
            if (mass >= asteroids[i])
            {
                mass += asteroids[i];
            }
            else if (mass >= 1e5)
                return true; // if the mass of the planet is greater than or equal to 1e5, it can destroy any asteroid
            else
            {
                return false;
            }
        }
        return true;
    }
};

// using min heap : Time complexity: O(nlogn) due to building the min heap and O(logn) for each asteroid. Space complexity: O(n) due to the min heap.
class Solution2
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap(asteroids.begin(), asteroids.end()); // min heap to store the asteroids

        while (!minHeap.empty())
        {
            int asteroid = minHeap.top(); // get the smallest asteroid
            minHeap.pop();                // remove the smallest asteroid

            if (mass >= asteroid)
            {
                mass += asteroid; // if the mass of the planet is greater than or equal to the mass of the asteroid, destroy the asteroid and add its mass to the planet
            }
            else if (mass >= 1e5)
                return true; // if the mass of the planet is greater than or equal to 1e5, it can destroy any asteroid
            else
            {
                return false; // if the mass of the planet is less than the mass of the asteroid, return false
            }
        }

        return true; // if we were able to destroy all asteroids, return true
    }
};