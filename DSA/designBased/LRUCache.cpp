// 146. LRU Cache
// Medium
// Topics
// premium lock icon
// Companies
// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

// Example 1:

// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4

// Constraints:

// 1 <= capacity <= 3000
// 0 <= key <= 104
// 0 <= value <= 105
// At most 2 * 105 calls will be made to get and put.

// approach: using a hash map to store the key-value pairs and a doubly linked list to store the keys in the order of their usage, and when we get a key, we move it to the front of the linked list, and when we put a key-value pair, we add it to the front of the linked list and if the number of keys exceeds the capacity, we remove the least recently used key from the linked list and the hash map.

// DLL makes it easy to add and remove nodes from the front and back of the list, and the hash map allows us to access the nodes in O(1) time complexity.

#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    list<int> cache;                                       // doubly linked list to store the key in the order of their usage
    unordered_map<int, pair<list<int>::iterator, int>> mp; // hash map to store the key-value pairs and the iterator to the corresponding node in the linked list
    int capacity;                                          // variable to store the capacity of the cache

    LRUCache(int capacity)
    {
        this->capacity = capacity; // initialize the capacity of the cache
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end()) // if the key is not found in the cache, return -1
            return -1;

        cache.erase(mp[key].first);    // remove the key from the linked list since it is accessed and we need to move it to the front of the linked list to mark it as most recently used
        cache.push_front(key);         // add the key to the front of the linked list to mark it as most recently used
        mp[key].first = cache.begin(); // update the iterator of the key in the hash map to point to the new position of the key in the linked list
        return mp[key].second;         // return the value of the key
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end()) // if the key is already present in the cache, then we update its value and move it to the front of the linked list to mark it as most recently used
        {
            cache.erase(mp[key].first);       // remove the key from the linked list since it is accessed and we need to move it to the front of the linked list to mark it as most recently used
            cache.push_front(key);            // add the key to the front of the linked list to mark it as most recently used
            mp[key] = {cache.begin(), value}; // update the iterator and value of the key in the hash map to point to the new position of the key in the linked list and update its value
        }
        else // if the key is not present in the cache, then we add it to the front of the linked list and if the number of keys exceeds the capacity, we remove the least recently used key from the linked list and the hash map.
        {
            if (cache.size() == capacity) // if the number of keys in the cache is equal to the capacity, then we remove the least recently used key from the linked list and the hash map.
            {
                int lruKey = cache.back(); // get the least recently used key from the back of the linked list
                cache.pop_back();          // remove the least recently used key from the linked list
                mp.erase(lruKey);          // remove the least recently used key from the hash map
            }

            cache.push_front(key);            // add the new key to the front of the linked list to mark it as most recently used
            mp[key] = {cache.begin(), value}; // add the new key-value pair to the hash map with an iterator pointing to its position in the linked list
        }
    }
};

// brute force using vector of pairs -> TLE
class LRUCache1
{
public:
    vector<pair<int, int>> cache; // vector to store the key-value pairs in the order of their usage
    int capacity;                 // variable to store the capacity of the cache

    LRUCache1(int capacity)
    {
        this->capacity = capacity; // initialize the capacity of the cache
    }

    int get(int key)
    {
        for (int i = 0; i < cache.size(); i++)
        {
            if (cache[i].first == key)
            {
                int value = cache[i].second;    // store the value of the key
                cache.erase(cache.begin() + i); // remove the key-value pair from the cache
                cache.push_back({key, value});  // add the key-value pair to the end of the cache to mark it as most recently used
                return value;                   // return the value of the key
            }
        }

        return -1; // if the key is not found in the cache, return -1
    }

    void put(int key, int value)
    {
        for (int i = 0; i < cache.size(); i++)
        {
            if (cache[i].first == key) // if the key is already present in the cache, then we update its value and move it to the end of the cache to mark it as most recently used
            {
                cache.erase(cache.begin() + i); // remove the key-value pair from the cache
                cache.push_back({key, value});  // add the key-value pair to the end of the cache to mark it as most recently used
                return;                         // return from the function since we have updated the value of the key
            }
        }

        if (cache.size() == capacity) // if the number of keys in the cache is equal to the capacity, then we remove the least recently used key from the cache
        {
            cache.erase(cache.begin());    // remove the first key-value pair from the cache since it is the least recently used key
            cache.push_back({key, value}); // add the new key-value pair to the end of the cache to mark it as most recently used
        }
        else
        {
            cache.push_back({key, value}); // add the new key-value pair to the end of the cache to mark it as most recently used
        }
    }
};