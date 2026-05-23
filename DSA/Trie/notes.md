# Trie

- A tree-like data structure used to store a dynamic set of strings, where the location of each node represents a prefix of the strings.
- Each node contains an array of child nodes, typically with a size equal to the number of possible characters in the alphabet.
- The root node is empty, and each path from the root to a leaf node represents a string in the set.
- Commonly used for implementing autocomplete and spell-checking features.

## Key Concepts of Trie

1. Insertion: To insert a string into a trie, we start from the root and follow the path corresponding to the characters of the string. If a node does not exist for a character, we create a new node. Once we reach the end of the string, we mark the last node as a leaf node to indicate that it represents a complete string.
2. Search: To search for a string in a trie, we start from the root and follow the path corresponding to the characters of the string. If we reach a node that does not exist for a character, it means the string is not present in the trie. If we reach the end of the string and the last node is marked as a leaf node, it means the string is present in the trie.
3. Deletion: To delete a string from a trie, we first search for the string in the trie. If the string is found, we unmark the last node as a leaf node. If the last node has no children, we can delete it and continue deleting parent nodes until we reach a node that has other children or is marked as a leaf node.

## Time Complexity of Trie Operations

- Insertion: O(m), where m is the length of the string being inserted.
- Search: O(m), where m is the length of the string being searched.
- Deletion: O(m), where m is the length of the string being deleted.

## Space Complexity of Trie

- The space complexity of a trie can be O(n \* m), where n is the number of strings in the trie and m is the average length of the strings. However, in practice, the space complexity can be reduced by using techniques such as compressing common prefixes or using a more compact representation for the child nodes.

## Applications of Trie

- Autocomplete: Tries can be used to implement autocomplete features in search engines and text editors. By traversing the trie based on the user's input, we can quickly find all strings that start with the given prefix.
- Spell Checking: Tries can be used to implement spell-checking features by storing a dictionary of valid words. By searching for a word in the trie, we can determine if it is spelled correctly or suggest alternatives based on similar prefixes.
- IP Routing: Tries can be used in networking to implement IP routing tables, where each node represents a prefix of an IP address. This allows for efficient routing of packets based on the longest prefix match.
- Data Compression: Tries can be used in data compression algorithms, such as Huffman coding, to represent the frequency of characters in a compact way. By building a trie based on the frequency of characters, we can create an efficient encoding scheme for compressing data.

## Variations of Trie

- Suffix Trie: A trie that stores all the suffixes of a given string. It is used for pattern matching and substring search problems.
- Compressed Trie: A trie that compresses common prefixes into a single node, reducing the space complexity of the trie. This is also known as a radix tree or a prefix tree.
- Ternary Search Trie: A trie that uses three child nodes for each character: one for characters less than the current character, one for characters equal to the current character, and one for characters greater than the current character. This can reduce the space complexity of the trie while still allowing for efficient search and insertion operations.
- Patricia Trie: A trie that uses a more compact representation for the child nodes, where each node can represent multiple characters. This can further reduce the space complexity of the trie while still allowing for efficient search and insertion operations.
- DAWG (Directed Acyclic Word Graph): A trie that is optimized for storing a large number of strings with common prefixes. It uses a directed acyclic graph structure to share common prefixes and reduce the space complexity of the trie.

## implementation of Trie in C++

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

struct TrieNode {
    // can use array of size 26 for lowercase letters, but using unordered_map for flexibility
    // TrieNode* children[26]; // Array to store child nodes for each character (assuming only lowercase letters)
    unordered_map<char, TrieNode*> children; // Map to store child nodes for each character
    bool isEndOfWord; // Flag to indicate if the node represents the end of a word

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie();
    void insert(string word);
    bool search(string word);
    bool startsWith(string prefix);
};
```

```cpp
Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(string word) {
    TrieNode* currentNode = root;
    for (char c : word) {
        if (currentNode->children.find(c) == currentNode->children.end()) {
            currentNode->children[c] = new TrieNode();
        }
        currentNode = currentNode->children[c];
    }
    currentNode->isEndOfWord = true;
}

bool Trie::search(string word) {
    TrieNode* currentNode = root;
    for (char c : word) {
        if (currentNode->children.find(c) == currentNode->children.end()) {
            return false;
        }
        currentNode = currentNode->children[c];
    }
    return currentNode->isEndOfWord;
}

bool Trie::startsWith(string prefix) {
    TrieNode* currentNode = root;
    for (char c : prefix) {
        if (currentNode->children.find(c) == currentNode->children.end()) {
            return false;
        }
        currentNode = currentNode->children[c];
    }
    return true;
}
```
