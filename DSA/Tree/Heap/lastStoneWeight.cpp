// 1046. Last Stone Weight
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are given an array of integers stones where stones[i] is the weight of the ith stone.

// We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

// If x == y, both stones are destroyed, and
// If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
// At the end of the game, there is at most one stone left.

// Return the weight of the last remaining stone. If there are no stones left, return 0.

// Example 1:

// Input: stones = [2,7,4,1,8,1]
// Output: 1
// Explanation:
// We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
// we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
// we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
// we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
// Example 2:

// Input: stones = [1]
// Output: 1

// Constraints:

// 1 <= stones.length <= 30
// 1 <= stones[i] <= 1000

// approach 1: we sort the array and then we keep smashing the two heaviest stones until we have at most one stone left. This approach has a time complexity of O(nlogn) due to sorting.

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        while (stones.size() > 1)
        {                                       // keep smashing the two heaviest stones until we have at most one stone left
            sort(stones.begin(), stones.end()); // sort the array to get the two heaviest stones
            int x = stones[stones.size() - 2];  // get the second heaviest stone
            int y = stones[stones.size() - 1];  // get the heaviest stone
            if (x == y)
            {                      // if both stones are of equal weight, both are destroyed
                stones.pop_back(); // remove the heaviest stone
                stones.pop_back(); // remove the second heaviest stone
            }
            else
            {                                      // if both stones are of different weight, the lighter stone is destroyed and the heavier stone has new weight y - x
                stones.pop_back();                 // remove the heaviest stone
                stones[stones.size() - 1] = y - x; // update the weight of the heavier stone
            }
        }
        return stones.size() == 0 ? 0 : stones[0]; // return the weight of the last remaining stone, if there are no stones left, return 0
    }
};

// approach 2: we can use a max heap to get the two heaviest stones in O(logn) time. This approach has a time complexity of O(nlogn) due to building the max heap and O(logn) for each smash operation.

#include <bits/stdc++.h>
using namespace std;

class Solution2
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> maxHeap; // max heap to store the stones

        for (int stone : stones) // add all the stones to the max heap
            maxHeap.push(stone);

        while (maxHeap.size() > 1)
        {                          // keep smashing the two heaviest stones until we have at most one stone left
            int x = maxHeap.top(); // get the heaviest stone
            maxHeap.pop();         // remove the heaviest stone
            int y = maxHeap.top(); // get the second heaviest stone
            maxHeap.pop();         // remove the second heaviest stone

            if (x != y)              // if both stones are of different weight, the lighter stone is destroyed and the heavier stone has new weight y - x
                maxHeap.push(x - y); // add the new weight of the heavier stone to the max heap
        }

        return maxHeap.empty() ? 0 : maxHeap.top(); // return the weight of the last remaining stone, if there are no stones left, return 0
    }
};