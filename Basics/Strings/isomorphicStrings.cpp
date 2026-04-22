// 205. Isomorphic Strings
// Easy
// Topics
// premium lock icon
// Companies
// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

// Example 1:

// Input: s = "egg", t = "add"

// Output: true

// Explanation:

// The strings s and t can be made identical by:

// Mapping 'e' to 'a'.
// Mapping 'g' to 'd'.
// Example 2:

// Input: s = "f11", t = "b23"

// Output: false

// Explanation:

// The strings s and t can not be made identical as '1' needs to be mapped to both '2' and '3'.

// Example 3:

// Input: s = "paper", t = "title"

// Output: true

// Constraints:

// 1 <= s.length <= 5 * 104
// t.length == s.length
// s and t consist of any valid ascii character.

// approach
// We can use two hash maps to store the mapping of characters from s to t and from t to s. We iterate through both strings simultaneously and check if the current characters in s and t have already been mapped. If they have been mapped, we check if the mapping is consistent. If they haven't been mapped, we create a new mapping. If at any point we find an inconsistency, we return false. If we successfully iterate through both strings without finding any inconsistencies, we return true.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> sMap;
        unordered_map<char, char> tMap;

        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            // check if the current characters in s and t have already been mapped
            if (sMap.find(s[i]) != sMap.end() || tMap.find(t[i]) != tMap.end())
            {
                // if they have been mapped, check if the mapping is consistent
                if (sMap[s[i]] != t[i] || tMap[t[i]] != s[i])
                {
                    return false;
                }
            }
            else
            {
                // mapping if not already mapped
                sMap[s[i]] = t[i];
                tMap[t[i]] = s[i];
            }
        }
        return true;
    }

// We can also use two arrays to store the mapping of characters from s to t and from t to s. We can use the ASCII values of the characters as indices in the arrays. The rest of the logic is similar to the hash map approach.

    bool isIsomorphicUsingArrays(string s, string t)
    {
        int sMap[256] = {0};
        int tMap[256] = {0};

        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            // check if the current characters in s and t have already been mapped
            if (sMap[s[i]] != tMap[t[i]])
                return false;
            
            // update the mapping, we use i + 1 to avoid the default value of 0 in the arrays
            sMap[s[i]] = i + 1;
            tMap[t[i]] = i + 1;
        }

        return true;
    }
};