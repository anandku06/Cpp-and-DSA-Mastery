// 460. LFU Cache
// Hard
// Topics
// premium lock icon
// Companies
// Design and implement a data structure for a Least Frequently Used (LFU) cache.

// Implement the LFUCache class:

// LFUCache(int capacity) Initializes the object with the capacity of the data structure.
// int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
// void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
// To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

// When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

// The functions get and put must each run in O(1) average time complexity.

// Example 1:

// Input
// ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, 3, null, -1, 3, 4]

// Explanation
// // cnt(x) = the use counter for key x
// // cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
// LFUCache lfu = new LFUCache(2);
// lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
// lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
// lfu.get(1);      // return 1
//                  // cache=[1,2], cnt(2)=1, cnt(1)=2
// lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
//                  // cache=[3,1], cnt(3)=1, cnt(1)=2
// lfu.get(2);      // return -1 (not found)
// lfu.get(3);      // return 3
//                  // cache=[3,1], cnt(3)=2, cnt(1)=2
// lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
//                  // cache=[4,3], cnt(4)=1, cnt(3)=2
// lfu.get(1);      // return -1 (not found)
// lfu.get(3);      // return 3
//                  // cache=[3,4], cnt(4)=1, cnt(3)=3
// lfu.get(4);      // return 4
//                  // cache=[4,3], cnt(4)=2, cnt(3)=3

// Constraints:

// 1 <= capacity <= 104
// 0 <= key <= 105
// 0 <= value <= 109
// At most 2 * 105 calls will be made to get and put.

// approach: Use a combination of a hash map and a list of lists to maintain the cache. The hash map will store the key-value pairs, and the list of lists will store the keys grouped by their frequencies.

#include <bits/stdc++.h>
using namespace std;

class LFUCache
{
public:
    int capacity;                                       // The maximum number of items that can be stored in the cache.
    int size;                                           // The current number of items in the cache.
    map<int, list<vector<int>>> freq;                   // A map to store the frequency of each key and its corresponding list of keys.
    unordered_map<int, list<vector<int>>::iterator> mp; // A hash map to store the key-value pairs and their corresponding iterators in the cache.

    void makeMostFrequent(int key, int value)
    {
        auto &vec = *(mp[key]); // Get the iterator to the key-value pair in the cache.
        vec[1] = value;         // Update the value associated with the key.
        int freqCount = vec[2]; // Get the frequency count of the key.

        // Remove the key from its current frequency list.
        freq[freqCount].erase(mp[key]);

        // If the frequency list is empty, remove it from the frequency map.
        if (freq[freqCount].empty())
            freq.erase(freqCount);

        freqCount++; // Increment the frequency count of the key.

        // Add the key to the new frequency list.
        freq[freqCount].push_front({key, value, freqCount});

        // Update the iterator in the hash map to point to the new position of the key in the cache.
        mp[key] = freq[freqCount].begin();
    }

    LFUCache(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1; // If the key is not found in the cache, return -1.

        else
        {
            auto vec = *(mp[key]); // Get the iterator to the key-value pair in the cache.
            int value = vec[1];    // Get the value associated with the key.

            makeMostFrequent(key, value); // Update the frequency of the key and move it to the appropriate position in the cache.

            return value; // Return the value associated with the key.
        }
    }

    void put(int key, int value)
    {
        // If the capacity of the cache is 0, do nothing and return.
        if (capacity == 0)
            return;

        // If the key is already present in the cache, update its value and frequency.
        if (mp.find(key) != mp.end())
        {
            auto vec = *(mp[key]);        // Get the iterator to the key-value pair in the cache.
            makeMostFrequent(key, value); // Update the frequency of the key and move it to the appropriate position in the cache.
            return;
        }
        // If not present, check if the cache is at full capacity.
        else
        {
            // If the cache is at full capacity, remove the least frequently used key.
            if (size == capacity)
            {
                // Get the least frequently used key from the frequency map.
                auto it = freq.begin();
                auto &lfuList = it->second;      // Get the list of keys with the least frequency.
                auto lfuKey = lfuList.back()[0]; // Get the least recently used key from the list.

                // Remove the least frequently used key from the cache and frequency map.
                mp.erase(lfuKey);   // Remove the key from the hash map.
                lfuList.pop_back(); // Remove the key from the frequency list.

                // If the frequency list is empty, remove it from the frequency map.
                if (lfuList.empty())
                    freq.erase(it->first);

                // Add the new key to the frequency list with a frequency of 1.
                freq[1].push_front(vector<int>({key, value, 1})); // Add the new key to the frequency list with a frequency of 1.

                // Update the iterator in the hash map to point to the new position of the key in the cache.
                mp[key] = freq[1].begin();
            }
            // If the cache is not at full capacity, add the new key to the frequency list with a frequency of 1.
            else
            {
                size++;                                           // Increment the size of the cache.
                freq[1].push_front(vector<int>({key, value, 1})); // Add the new key to the frequency list with a frequency of 1.

                // Update the iterator in the hash map to point to the new position of the key in the cache.
                mp[key] = freq[1].begin();
            }
        }
    }
};