// 981. Time Based Key-Value Store
// Medium
// Topics
// premium lock icon
// Companies
// Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

// Implement the TimeMap class:

// TimeMap() Initializes the object of the data structure.
// void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
// String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".

// Example 1:

// Input
// ["TimeMap", "set", "get", "get", "set", "get", "get"]
// [[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
// Output
// [null, null, "bar", "bar", null, "bar2", "bar2"]

// Explanation
// TimeMap timeMap = new TimeMap();
// timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
// timeMap.get("foo", 1);         // return "bar"
// timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
// timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
// timeMap.get("foo", 4);         // return "bar2"
// timeMap.get("foo", 5);         // return "bar2"

// Constraints:

// 1 <= key.length, value.length <= 100
// key and value consist of lowercase English letters and digits.
// 1 <= timestamp <= 107
// All the timestamps timestamp of set are strictly increasing.
// At most 2 * 105 calls will be made to set and get.

// approach: Using Binary Search
// Intuition
// We can use a hash map to store the key-value pairs along with their timestamps. The key will be the string key and the value will be a vector of pairs, where each pair consists of a timestamp and the corresponding value. When we call the set function, we will insert the key-value pair into the hash map. When we call the get function, we will first check if the key exists in the hash map. If it does not exist, we will return an empty string. If it does exist, we will perform a binary search on the vector of pairs to find the largest timestamp that is less than or equal to the given timestamp. We will return the corresponding value for that timestamp.

#include <bits/stdc++.h>
using namespace std;

class TimeMap
{
public:
    unordered_map<string, vector<pair<int, string>>> timeMap; // hash map to store key-value pairs along with their timestamps
    // why using vector of pairs? Because we need to store multiple values for the same key at different timestamps, and we need to be able to perform a binary search on the timestamps to find the correct value for a given timestamp.

    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        pair<int, string> entry = {timestamp, value}; // create a pair of timestamp and value
        timeMap[key].push_back(entry);                // insert the pair into the vector corresponding to the key in the hash map
    }

    string get(string key, int timestamp)
    {
        if (timeMap.find(key) == timeMap.end()) // check if the key exists in the hash map
            return "";                          // if the key does not exist, return an empty string

        auto &entries = timeMap[key]; // get the vector of pairs corresponding to the key

        int n = entries.size(); // get the size of the vector
        string ans = "";        // initialize the answer to an empty string

        int left = 0;      // initialize left pointer for binary search
        int right = n - 1; // initialize right pointer for binary search

        // perform binary search to find the largest timestamp that is less than or equal to the given timestamp
        // using equal to condition bcz we need to find the largest timestamp that is less than or equal to the given timestamp, so we will update the answer whenever we find a timestamp that is less than or equal to the given timestamp, and we will continue searching for a larger timestamp until we exhaust the search space.
        while (left <= right)
        {
            int mid = left + (right - left) / 2; // calculate the mid index

            if (entries[mid].first <= timestamp) // if the timestamp at mid is less than or equal to the given timestamp
            {
                ans = entries[mid].second; // update the answer to the value at mid
                left = mid + 1;            // move the left pointer to mid + 1 to search for a larger timestamp
            }
            else
            {
                right = mid - 1; // move the right pointer to mid - 1 to search for a smaller timestamp
            }
        }

        return ans; // return the answer, which is the value corresponding to the largest timestamp that is less than or equal to the given timestamp
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */