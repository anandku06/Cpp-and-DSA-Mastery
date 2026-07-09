// Count Subarrays with given XOR
// Difficulty: MediumAccuracy: 58.86%Submissions: 99K+Points: 4
// Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.

// Note: It is guranteed that the total count will fit within a 32-bit integer.

// Examples:

// Input: arr[] = [4, 2, 2, 6, 4], k = 6
// Output: 4
// Explanation: The subarrays having XOR of their elements as 6 are [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6]. Hence, the answer is 4.
// Input: arr[] = [5, 6, 7, 8, 9], k = 5
// Output: 2
// Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]. Hence, the answer is 2.
// Input: arr[] = [1, 1, 1, 1], k = 0
// Output: 4
// Explanation: The subarrays are [1, 1], [1, 1], [1, 1] and [1, 1, 1, 1].
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 0 ≤ arr[i] ≤ 105
// 0 ≤ k ≤ 105

// approach: We can use a hashmap to store the frequency of the prefix XORs. We can iterate through the array and calculate the prefix XOR for each element. For each prefix XOR, we can check if there exists a prefix XOR that when XORed with the current prefix XOR gives us k. If it does, we can add the frequency of that prefix XOR to our count. We also need to check if the current prefix XOR is equal to k, in which case we increment our count by 1. Finally, we update the frequency of the current prefix XOR in the hashmap.

#include <bits/stdc++.h>
using namespace std;

class Brute_Solution
{
public:
    long subarrayXor(vector<int> &arr, int k)
    {
        int n = arr.size(); // get the size of the array
        int cnt = 0;        // initialize the count of subarrays with XOR equal to k

        for (int i = 0; i < n; i++)
        {
            int currXor = 0; // initialize the current XOR to 0
            for (int j = i; j < n; j++)
            {
                currXor ^= arr[j]; // calculate the XOR of the subarray from index i to j
                if (currXor == k)  // if the current XOR is equal to k, increment the count
                    cnt++;
            }
        }

        return cnt; // return the count of subarrays with XOR equal to k
    }
};

class Optimal_Solution
{
public:
    long subarrayXor(vector<int> &arr, int k)
    {
        unordered_map<int, int> freq; // hashmap to store the frequency of prefix XORs
        int currXor = 0;              // initialize the current prefix XOR to 0
        long cnt = 0;                 // initialize the count of subarrays with XOR equal to k

        for (int i = 0; i < arr.size(); i++)
        {
            currXor ^= arr[i]; // calculate the current prefix XOR

            if (currXor == k) // if the current prefix XOR is equal to k, increment the count
                cnt++;

            int requiredXor = currXor ^ k; // calculate the required prefix XOR that when XORed with current prefix XOR gives us k

            if (freq.find(requiredXor) != freq.end()) // if the required prefix XOR exists in the hashmap, add its frequency to the count
                cnt += freq[requiredXor];

            freq[currXor]++; // update the frequency of the current prefix XOR in the hashmap
        }

        return cnt; // return the count of subarrays with XOR equal to k
    }
};