// 208. Implement Trie (Prefix Tree)
// Medium
// Topics
// premium lock icon
// Companies
// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

// Implement the Trie class:

// Trie() Initializes the trie object.
// void insert(String word) Inserts the string word into the trie.
// boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
// boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

// Example 1:

// Input
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// Output
// [null, null, true, false, true, null, true]

// Explanation
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // return True
// trie.search("app");     // return False
// trie.startsWith("app"); // return True
// trie.insert("app");
// trie.search("app");     // return True

// Constraints:

// 1 <= word.length, prefix.length <= 2000
// word and prefix consist only of lowercase English letters.
// At most 3 * 104 calls in total will be made to insert, search, and startsWith.

#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    bool isEndOfWord;
    unordered_map<char, TrieNode *> children;

    TrieNode() : isEndOfWord(false) {}
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode(); // Initialize the root of the trie
    }

    void insert(string word)
    {
        TrieNode *currentNode = root; // Start from the root node
        for (char c : word)
        {
            if (currentNode->children.find(c) == currentNode->children.end())
            {
                currentNode->children[c] = new TrieNode(); // Create a new node if it doesn't exist
            }
            currentNode = currentNode->children[c]; // Move to the child node
        }
        currentNode->isEndOfWord = true; // Mark the end of the word
    }

    bool search(string word)
    {
        TrieNode *currentNode = root; // Start from the root node
        for (char c : word)
        {
            if (currentNode->children.find(c) == currentNode->children.end())
            {
                return false; // Word not found
            }
            currentNode = currentNode->children[c]; // Move to the child node
        }
        return currentNode->isEndOfWord; // Return true if it's the end of a word
    }

    bool startsWith(string prefix)
    {
        TrieNode *currentNode = root; // Start from the root node
        for (char c : prefix)
        {
            if (currentNode->children.find(c) == currentNode->children.end())
            {
                return false; // Prefix not found
            }
            currentNode = currentNode->children[c]; // Move to the child node
        }
        return true; // Prefix found
    }
};