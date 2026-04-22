// 451. Sort Characters By Frequency
// Medium
// Topics
// premium lock icon
// Companies
// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.

// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:

// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:

// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.

// Constraints:

// 1 <= s.length <= 5 * 105
// s consists of uppercase and lowercase English letters and digits.

// approach (heap)
// We can use a hash map to count the frequency of each character in the string. Then we can use a priority queue (max heap) to store the characters based on their frequency. We can then build the result string by repeatedly extracting the character with the highest frequency from the priority queue and appending it to the result string until the priority queue is empty. The time complexity of this approach is O(n log k) where n is the length of the string and k is the number of unique characters in the string. The space complexity is O(k) for storing the frequency of characters in the hash map and O(k) for storing the characters in the priority queue.

// approach (comparator)
// We can use a hash map to count the frequency of each character in the string. Then we can create a vector of pairs (character, frequency) and sort it based on the frequency in decreasing order. Finally, we can build the result string by iterating through the sorted vector and appending each character to the result string based on its frequency. The time complexity of this approach is O(n + k log k) where n is the length of the string and k is the number of unique characters in the string. The space complexity is O(k) for storing the frequency of characters in the hash map and O(k) for storing the characters in the vector.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool comp(pair<int, char> p1, pair<int, char> p2) {}

    vector<char> sortByFrequency(string s)
    {
        pair<int, char> freq[26]; // only for lowercase chars

        for (int i = 0; i < 26; i++)
        {
            freq[i] = {0, i + 'a'};
        }

        for (char c : s)
        {
            freq[c - 'a'].first++;
        }

        sort(freq, freq + 26, comp);

        vector<char> res;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i].first != 0)
                res.push_back(freq[i].second);
        }

        return res;
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution2
{
public:
    typedef pair<char, int> P;
    string frequencySort(string s)
    {
        vector<P> vec(123);

        for (char ch : s)
        {
            vec[ch] = {ch, vec[ch].second + 1};
        }

        auto lambda = [&](P p1, P p2)
        {
            return p1.second > p2.second;
        };

        sort(vec.begin(), vec.end(), lambda);

        string res = "";

        for (int i = 0; i < 123; i++)
        {
            char c = vec[i].first;
            int freq = vec[i].second;

            if (freq > 0)
            {
                res += string(freq, c);
            }
        }

        return res;
    }
};

// lambda function
// auto lambda = [capture](parameters) { body };

// [] (Capture Clause): Ye batata hai ki function ke bahar ke variables ko andar use karna hai ya nahi. Aapne [&] use kiya hai, matlab bahar ke variables "reference" se accessible hain.

// (P p1, P p2): Ye inputs hain. sort function do elements ko compare karne ke liye bhejega.

// { return p1.second > p2.second; }: Ye logic hai. Aap keh rahe hain: "Agar pehle element ki frequency doosre se badi hai, toh use pehle rakho (Descending Order)."