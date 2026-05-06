// 138. Copy List with Random Pointer
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

// Return the head of the copied linked list.

// The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

// val: an integer representing Node.val
// random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
// Your code will only be given the head of the original linked list.

// Example 1:

// Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Example 2:

// Input: head = [[1,1],[2,1]]
// Output: [[1,1],[2,1]]
// Example 3:

// Input: head = [[3,null],[3,0],[3,null]]
// Output: [[3,null],[3,0],[3,null]]

// Constraints:

// 0 <= n <= 1000
// -104 <= Node.val <= 104
// Node.random is null or is pointing to some node in the linked list.

// approach 1: using a hash map to store the mapping of original nodes to their corresponding copied nodes and then setting the next and random pointers of the copied nodes using the hash map

struct ListNode
{
    int data;
    ListNode *next;
    ListNode *random;
    ListNode(int val) : data(val), next(nullptr), random(nullptr) {}
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *copyRandomList(ListNode *head)
    {
        if (!head)
            return nullptr; // if head is nullptr, then return nullptr

        unordered_map<ListNode *, ListNode *> mp; // hash map to store the mapping of original nodes to their corresponding copied nodes
        ListNode *curr = head;                    // pointer to traverse the original linked list
        ListNode *prev = nullptr;                 // pointer to keep track of the previous node in the copied linked list
        ListNode *newHead = nullptr;              // pointer to store the head of the copied linked list

        // traverse the original linked list and create the copied nodes and store the mapping in the hash map
        while (curr)
        {
            ListNode *newNode = new ListNode(curr->data); // create a new node with the same value as the current node
            mp[curr] = newNode;                           // store the mapping of the current node to the new node in the hash map

            if (newHead == nullptr) // if newHead is nullptr, then set it to the new node
            {
                newHead = newNode;
                prev = newHead; // set prev to newHead since it's the first node in the copied linked list
            }
            else // if newHead is not nullptr, then point the next pointer of the previous node to the new node and update prev to the new node
            {
                prev->next = newNode;
                prev = newNode;
            }

            curr = curr->next; // move to the next node in the original linked list
        }

        // traverse the original linked list again and set the random pointers of the copied nodes using the hash map
        curr = head;                  // reset the current pointer to the head of the original linked list
        ListNode *copyCurr = newHead; // pointer to traverse the copied linked list

        while (curr)
        {
            if (curr->random == nullptr)
            {
                copyCurr->random = nullptr; // if the random pointer of the current node in the original linked list is nullptr, then set the random pointer of the corresponding node in the copied linked list to nullptr
            }
            else
            {
                copyCurr->random = mp[curr->random]; // set the random pointer of the corresponding node in the copied linked list to the new node corresponding to the random pointer of the current node in the original linked list using the hash map
            }

            curr = curr->next;         // move to the next node in the original linked list
            copyCurr = copyCurr->next; // move to the next node in the copied linked list
        }

        return newHead; // return the head of the copied linked list
    }
};

// approach 2: using a single pass to create the copied nodes and set the next and random pointers of the copied nodes by interleaving the copied nodes with the original nodes in the linked list and then separating the original and copied linked lists.
// i.e. we can create the copied nodes and insert them between the original nodes in the linked list and then set the random pointers of the copied nodes using the next pointers of the original nodes and then finally separate the original and copied linked lists.

class Solution2
{
public:
    ListNode *copyRandomList(ListNode *head)
    {
        if (!head)
            return nullptr; // if head is nullptr, then return nullptr

        ListNode *curr = head; // pointer to traverse the original linked list

        // create the copied nodes and insert them between the original nodes in the linked list
        while (curr)
        {
            ListNode *newNode = new ListNode(curr->data); // create a new node with the same value as the current node
            newNode->next = curr->next;                   // point the next pointer of the new node to the next node of the current node
            curr->next = newNode;                         // point the next pointer of the current node to the new node
            curr = newNode->next;                         // move to the next original node in the linked list
        }

        curr = head; // reset the current pointer to the head of the original linked list
        // set the random pointers of the copied nodes using the next pointers of the original nodes
        while (curr)
        {
            if (curr->random)
            { // if the random pointer of the current node in the original linked list is not nullptr, then set the random pointer of the corresponding node in the copied linked list to the next node of the random pointer of the current node in the original linked list
                curr->next->random = curr->random->next;
            }
            else
            { // if the random pointer of the current node in the original linked list is nullptr, then set the random pointer of the corresponding node in the copied linked list to nullptr
                curr->next->random = nullptr;
            }

            curr = curr->next->next; // move to the next original node in the linked list
        }

        ListNode *newHead = head->next; // pointer to store the head of the copied linked list
        curr = head;                    // reset the current pointer to the head of the original linked list
        // separate the original and copied linked lists
        while (curr)
        {
            ListNode *temp = curr->next;                                     // store the next node of the current node in the original linked list (which is the corresponding node in the copied linked list)
            curr->next = curr->next == nullptr ? nullptr : curr->next->next; // point the next pointer of the current node in the original linked list to the next original node in the linked list
            temp->next = temp->next == nullptr ? nullptr : temp->next->next; // point the next pointer of the current node in the copied linked list to the next copied node in the linked list

            curr = curr->next; // move to the next original node in the linked list
            temp = temp->next; // move to the next copied node in the linked list
        }

        return newHead; // return the head of the copied linked list
    }
};