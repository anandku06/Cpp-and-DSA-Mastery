// Encode and Decode Strings
// Medium
// Topics
// Company Tags
// Hints
// Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

// Machine 1 (sender) has the function:

// string encode(vector<string> strs) {
//     // ... your code
//     return encoded_string;
// }
// Machine 2 (receiver) has the function:

// vector<string> decode(string s) {
//     //... your code
//     return strs;
// }
// So Machine 1 does:

// string encoded_string = encode(strs);
// and Machine 2 does:

// vector<string> strs2 = decode(encoded_string);
// strs2 in Machine 2 should be the same as strs in Machine 1.

// Implement the encode and decode methods.

// Example 1:

// Input: dummy_input = ["Hello","World"]

// Output: ["Hello","World"]

// Explanation:
// Machine 1:
// Codec encoder = new Codec();
// String msg = encoder.encode(strs);
// Machine 1 ---msg---> Machine 2

// Machine 2:
// Codec decoder = new Codec();
// String[] strs = decoder.decode(msg);
// Example 2:

// Input: dummy_input = [""]

// Output: [""]

// Constraints:

// 0 <= strs.length < 100
// 0 <= strs[i].length < 200
// strs[i] contains any possible characters out of 256 valid ASCII characters.

// Follow up: Could you write a generalized algorithm to work on any possible set of characters?

// approach 1: using a delimiter to separate the strings in the encoded string, and then using the delimiter to split the encoded string back into the original list of strings. The time complexity of this approach is O(n) where n is the total length of all the strings in the list.

// approach 2: using a length prefix to encode the length of each string in the encoded string, and then using the length prefix to decode the encoded string back into the original list of strings. The time complexity of this approach is O(n) where n is the total length of all the strings in the list.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";

        string encodedString = "";

        for (string str : strs)
        {
            encodedString += to_string(str.size()) + "#" + str; // encoding the length of the string and the string itself
        }
        return encodedString;
    }

    vector<string> decode(string s)
    {
        vector<string> decodedStrings;

        int i = 0;
        while (i < s.size())
        {
            int j = i;
            while (s[j] != '#') // finding the index of the delimiter
            {
                j++;
            }
            int length = stoi(s.substr(i, j - i));             // getting the length of the string
            decodedStrings.push_back(s.substr(j + 1, length)); // getting the string itself
            i = j + 1 + length;                                // moving to the next string
        }

        return decodedStrings;
    }
};