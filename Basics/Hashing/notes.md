# Hashing

- Hashing is a technique used to uniquely identify a specific object from a group of similar objects. It is commonly used in data structures like hash tables, which allow for efficient data retrieval.
- A hash function is a function that takes an input (or "key") and returns a fixed-size string of bytes. The output is typically a hash code that represents the input data. A good hash function should distribute the keys uniformly across the hash table to minimize collisions.
- A collision occurs when two different keys produce the same hash code. To handle collisions, various techniques have been developed, such as chaining (where each bucket in the hash table contains a list of entries) and open addressing (where the hash table itself is probed to find an empty slot).
- Hash tables provide average-case O(1) time complexity for search, insert, and delete operations, making them very efficient for many applications. However, the performance can degrade to O(n) in the worst case if there are many collisions.
- Hashing is widely used in various applications, including databases, caching, and cryptography.
- In cryptography, hash functions are used to create a unique representation of data, which can be used for data integrity verification and digital signatures. Cryptographic hash functions have specific properties, such as being deterministic, fast to compute, and resistant to collisions and pre-image attacks.
- Some common hash functions include MD5, SHA-1, and SHA-256. However, due to vulnerabilities in MD5 and SHA-1, they are no longer considered secure for cryptographic purposes, and SHA-256 is recommended for modern applications.
- When implementing a hash table, it is important to choose an appropriate size for the table and a good hash function to minimize collisions and ensure efficient performance. Additionally, resizing the hash table when it becomes too full can help maintain performance.
- In summary, hashing is a powerful technique for efficient data storage and retrieval, but it requires careful consideration of hash functions and collision resolution strategies to ensure optimal performance.

## Hashing in Arrays

- In the context of arrays, hashing provides an efficient method for solving problems like counting the frequency of elements. Consider the array arr[] = {5, 6, 5, 6, 9, 6}. To determine how many times the number 6 appears in this array, there are several approaches that can be taken.

### Method 1: Basic Traversal and Counting

The simplest method involves traversing the entire array and counting the occurrences of the number 6. Although this method is straightforward and works well for a single query, it requires a complete traversal of the array every time we need to count an element.

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {5, 6, 5, 6, 9, 6};
    int count = 0;
    for(int i = 0; i < 6; i++) {
        if(arr[i] == 6) {
            count++;
        }
    }
    cout << count << endl;  // Output: 3
    return 0;
}
```

### Method 2: Hashing for Efficient Counting

A more structured approach involves using hashing. Here, we store the frequency of all elements in a hash table (or array), where the index represents the element and the value at that index represents its count.

This preprocessing takes one full traversal of the array. While this does not provide a significant advantage when answering a single query (such as counting only the number 6), it becomes highly efficient when handling multiple queries, since each query can then be answered in constant time.

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {5, 6, 5, 6, 9, 6};
    int hashTable[10] = {0};
    for(int i = 0; i < 6; i++) {
        hashTable[arr[i]]++;
    }
    cout << hashTable[6] << endl;  // Output: 3
    return 0;
}
```

### Why Hashing is Advantageous?

The real advantage of hashing becomes evident when multiple queries are involved.
Suppose we need to count occurrences of several elements (e.g., 3, 5, 6, 9, etc.).

- Using Method 1, we would need to traverse the array for each query → O(n × q)
- Using Method 2, we preprocess once and answer each query instantly → O(n + q)

In such scenarios, Method 1 becomes inefficient due to repeated traversals, whereas hashing avoids redundant work by storing results upfront. This is where hashing clearly outperforms the basic traversal approach.

### Understanding ASCII Values in Character Hashing

The American Standard Code for Information Interchange (ASCII) is a character encoding standard that assigns numerical values to characters, with lowercase letters 'a' through 'z' being assigned values from 97 to 122. This simple numerical assignment allows characters to be easily manipulated and processed in hashing operations.

For instance, if there is a need to increment a value associated with the character 'a', the corresponding operation in terms of its ASCII value would be:

hash['a']++ translates to hash[97]++

This direct mapping between characters and their ASCII values allows for the creation of a hash table where each index corresponds to a specific character. When dealing with only lowercase alphabets, this hash table can be efficiently utilized by reducing the character’s ASCII value relative to 'a'.

#### Hashing for Lowercase Alphabets

When dealing exclusively with lowercase letters, the hash table can be further optimized by indexing relative to the character 'a'. For example:

hash['b' - 'a'] = hash[1]

In this context, 'b' - 'a' computes to 1, which allows for efficient storage and retrieval in a zero-indexed array structure. This technique not only simplifies the process but also reduces the required space since only 26 indices (0 through 25) need to be managed, rather than the full ASCII range.

### Hashing Implementations Across Programming Languages

- C++
  In C++, one can utilize either an unordered_map or a map to implement character hashing. The choice between these structures depends on the specific use case:

unordered_map: Offers an average time complexity of O(1) for insertions, deletions, and lookups. However, in the worst-case scenario, typically due to hash collisions, the time complexity can degrade to O(N).
map: Implements a balanced binary tree, offering a guaranteed time complexity of O(log N) for all operations, regardless of collisions.

- Java
  Java provides similar data structures for character hashing, with analogous performance characteristics:

HashMap: Like unordered_map in C++, HashMap offers an average time complexity of O(1). However, due to collisions, its worst-case performance can degrade to O(N).
TreeMap: Functions similarly to map in C++, with a time complexity of O(log N), ensuring consistent performance across all operations.

### Division Method: A Detailed Explanation

The division method is one of the simplest and most commonly used hashing techniques. The fundamental idea behind this method is to divide the key by a suitable prime number and use the remainder as the hash value. The choice of the prime number is crucial as it ensures a more uniform distribution of hash values, thereby minimizing collisions.

#### Steps of the Division Method

- Choose a Prime Number: The first step is to select a large prime number, denoted as p, which will serve as the divisor in the hashing process. Prime numbers are preferred because they tend to distribute hash values more uniformly across the available range.
- Compute the Hash Value: For a given key k, the hash value h(k) is computed using the formula:
  `h(k) = k % p`
- Here, the modulus operation (%) returns the remainder when the key k is divided by the prime number p. This remainder serves as the index in the hash table where the key will be stored.

#### Example of the Division Method

Consider a scenario where a set of keys {56, 75, 42, 88, 91} needs to be stored in a hash table. Let's choose a prime number p = 7 as the divisor.

For key 56: h(56) = 56 % 7 = 0 (Store at index 0)
For key 75: h(75) = 75 % 7 = 5 (Store at index 5)
For key 42: h(42) = 42 % 7 = 0 (Collision occurs at index 0)
For key 88: h(88) = 88 % 7 = 4 (Store at index 4)
For key 91: h(91) = 91 % 7 = 0 (Collision occurs at index 0)
In this example, multiple keys are mapped to the same index, leading to collisions at index 0. The division method alone does not address collisions, which is why additional techniques such as chaining are implemented internally to manage them.

### Folding Method

- The folding method is a hashing technique where the key is divided into equal parts, and these parts are added together to form the hash value. If the key cannot be evenly divided, the remaining digits can be handled by various strategies such as padding or wrapping around.

### Mid-Square Method

- The mid-square method involves squaring the key and then extracting a portion of the resulting digits, typically from the middle, to use as the hash value. This method benefits from its ability to spread out similar keys more uniformly across the hash table.

### Chaining in Division Method: Internal Implementation

- Chaining is a collision resolution technique commonly used in conjunction with the division method. When two keys hash to the same index, chaining stores them in a linked list or another secondary data structure at that index, thereby allowing multiple elements to occupy the same position in the hash table.

#### Steps of Chaining Implementation

- Initialize the Hash Table: Begin by creating an array of linked lists (or another secondary structure) where each element in the array corresponds to an index in the hash table.
- Insert Key into the Hash Table: For each key k, compute the hash value using the division method. If a collision occurs (i.e., the computed index is already occupied), append the new key to the linked list at that index.
- Resolve Collisions: In the event of multiple keys hashing to the same index, chaining ensures that each key is accessible by traversing the linked list at that index.

#### Example of Chaining with the Division Method

Using the same set of keys {56, 75, 42, 88, 91} and prime number p = 7, chaining can be implemented as follows:

For key 56: h(56) = 0 (Insert into the list at index 0)
For key 75: h(75) = 5 (Insert into the list at index 5)
For key 42: h(42) = 0 (Append to the list at index 0, which now contains 56 -> 42)
For key 88: h(88) = 4 (Insert into the list at index 4)
For key 91: h(91) = 0 (Append to the list at index 0, which now contains 56 -> 42 -> 91)
Chaining effectively resolves collisions by allowing multiple keys to coexist at the same index without overwriting each other. This method maintains the efficiency of the division method while ensuring that all keys are accessible, even in the presence of collisions.

### Problems and Challenges

While these hashing techniques are powerful, they are not without challenges:

- Collisions: Even with well-chosen hash functions, collisions are inevitable. Techniques like chaining help manage collisions, but they can introduce additional complexity and performance overhead.
- Load Factor: The efficiency of hashing is highly dependent on the load factor, which is the ratio of the number of elements to the number of available positions in the hash table. A high load factor increases the likelihood of collisions, while a low load factor can lead to inefficient use of memory.
- Choice of Hash Function: The choice of a hash function is critical in ensuring uniform distribution of keys. Poorly chosen hash functions can lead to clustering, where many keys map to the same or nearby indices, degrading performance.
- Memory Overhead: Techniques like chaining require additional memory to store linked lists or other secondary structures, which can become significant in large-scale applications.
