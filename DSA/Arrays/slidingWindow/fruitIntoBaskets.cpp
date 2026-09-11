// 904. Fruit Into Baskets
// Medium
// Topics
// premium lock icon
// Companies
// You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

// You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// Given the integer array fruits, return the maximum number of fruits you can pick.

// Example 1:

// Input: fruits = [1,2,1]
// Output: 3
// Explanation: We can pick from all 3 trees.
// Example 2:

// Input: fruits = [0,1,2,2]
// Output: 3
// Explanation: We can pick from trees [1,2,2].
// If we had started at the first tree, we would only pick from trees [0,1].
// Example 3:

// Input: fruits = [1,2,3,2,2]
// Output: 4
// Explanation: We can pick from trees [2,3,2,2].
// If we had started at the first tree, we would only pick from trees [1,2].

// Constraints:

// 1 <= fruits.length <= 105
// 0 <= fruits[i] < fruits.length

// approach : We can solve this problem using a sliding window approach. We can keep track of the two types of fruits in the baskets and the count of each type of fruit. We can use a map to store the count of each type of fruit. We can use two pointers, left and right, to represent the current window. We can move the right pointer to the right and add the fruit to the map. If the size of the map is greater than 2, we can move the left pointer to the right and remove the fruit from the map until the size of the map is less than or equal to 2. We can keep track of the maximum length of the window.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();

        int l = 0, r = 0, mx = 0;

        unordered_map<int, int> mp;

        while (r < n)
        {
            mp[fruits[r]]++;

            while (mp.size() > 2 && l <= r)
            {
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0)
                    mp.erase(fruits[l]);
                l++;
            }

            mx = max(mx, r - l + 1);
            r++;
        }

        return mx;
    }
};