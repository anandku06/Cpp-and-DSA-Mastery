// 458. Implement Trie II (Prefix Tree)
// POTD

// Core
// You need to design a Trie (prefix tree) with enhanced functionalities. Implement the class Trie that supports the following operations:

// void insert(string word) : Inserts the word into the Trie.
// int countWordsEqualTo(string word): Returns the number of times word was inserted into the Trie.
// int countWordsStartingWith(string prefix): Returns the number of words in the Trie that start with the given prefix.
// void erase(string word): Removes the word from the Trie. It is guaranteed that the word exists in the Trie before calling this function.
// Example 1:
// Input : operations : ["Trie", "insert", "insert", "insert", "countWordsEqualTo", "countWordsStartingWith", "erase", "countWordsEqualTo", "countWordsStartingWith"]

// values : [[], ["apple"], ["apple"], ["app"], ["apple"], ["app"], ["apple"], ["apple"], ["app"]]

// Output : [null, null, null, null, 2, 3, null, 1, 2]

// Explanation :

// Insert "apple" twice and "app" once.

// "apple" appears twice, "app" appears once, and prefix "app" appears in "apple" and "app" (total 3).

// Erase "apple" once. Now, "apple" appears once, "app" prefix count is 2.

// Example 2:
// Input : operations : ["Trie", "insert", "insert", "countWordsEqualTo", "countWordsStartingWith", "erase", "countWordsEqualTo", "countWordsStartingWith", "erase", "countWordsStartingWith"]

// values : [[], ["apple"], ["apple"], ["apple"], ["app"], ["apple"], ["apple"], ["app"], ["apple"], ["app"]]

// Output : [null, null, null, 1, 2, null, 0, 1]

// Explanation :

// Insert "banana", "band", then query prefix "ban" → count = 2 ("banana", "band").

// Erase "banana", now "banana" count is 0, prefix "ban" count is 1 ("band" remains).

// Now Your Turn!
// Pick the correct output for the given input
// Input : operations : ["Trie", "insert", "insert", "insert", "countWordsEqualTo", "countWordsStartingWith", "erase", "countWordsEqualTo", "countWordsStartingWith", "erase", "countWordsEqualTo", "countWordsStartingWith"]

// values : [[], ["dog"], ["door"], ["dear"], ["dog"], ["do"], ["dog"], ["dog"], ["do"], ["door"], ["door"], ["do"]]

// [null, null, null, null, 1, 2, null, 0, 1, null, 0, 0]

// [null, null, null, null, 1, 1, null, 0, 1, null, 0, 0]

// [null, null, null, null, 1, 2, null, 0, 0, null, 0, 0]

// [null, null, null, null, 1, 2, null, 0, 1, null, 0, 1]
// Still unsure what the problem is asking ?

// Let’s go through a few more examples, step by step, to make it clearer.

// Constraints:
// 1 <= word.length, prefix.length <= 2000
// word and prefix consist only of lowercase English letters.
// At most 3 * 10⁴ calls in total will be made to insert, countWordsEqualTo, countWordsStartingWith, and erase.
// It is guaranteed that for any function call to erase, the string word will exist in the trie.

// Approach: Using Trie Data Structure
// Intuition
// A Trie (prefix tree) is a tree-like data structure that stores a dynamic set of strings, where the keys are usually strings. Each node in the Trie represents a single character of a string, and the path from the root to a node represents a prefix of the strings stored in the Trie. This structure allows for efficient insertion, search, and deletion of strings, as well as counting occurrences of words and prefixes.

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children; // Map to store child nodes
    int countWords;                           // Count of words ending at this node
    int countPrefix;                          // Count of words having this prefix
};

class Trie
{
public:
    TrieNode *root; // Root node of the Trie

    TrieNode()
    {
        root = new TrieNode(); // Initialize the root node
        countWords = 0;        // Initialize word count
        countPrefix = 0;       // Initialize prefix count
    }

    void insert(string word)
    {
        TrieNode *temp = root; // Start from the root node
        for (char c : word)
        {
            if (!temp->children.count(c))
            {
                temp->children[c] = new TrieNode(); // Create a new node if it doesn't exist
            }
            temp->prefixCount++; // Increment prefix count for the current node
            temp = temp->children[c];
        }
        temp->countWords++; // Increment word count for the final node
    }

    int countWordsEqualTo(string word)
    {
        TrieNode *temp = root; // Start from the root node
        for (char c : word)
        {
            if (!temp->children.count(c))
            {
                return 0; // If the character doesn't exist, return 0
            }
            temp = temp->children[c];
        }
        return temp->countWords; // Return the count of words ending at this node
    }

    int countWordsStartingWith(string prefix)
    {
        TrieNode *temp = root; // Start from the root node
        for (char c : prefix)
        {
            if (!temp->children.count(c))
            {
                return 0; // If the character doesn't exist, return 0
            }
            temp = temp->children[c];
        }
        return temp->prefixCount; // Return the count of words having this prefix
    }

    void erase(string word)
    {
        TrieNode *temp = root; // Start from the root node
        for (char c : word)
        {
            if (!temp->children.count(c))
            {
                return; // If the character doesn't exist, return
            }
            temp->prefixCount--; // Decrement prefix count for the current node
            temp = temp->children[c];
        }
        temp->countWords--; // Decrement word count for the final node
    } 
};