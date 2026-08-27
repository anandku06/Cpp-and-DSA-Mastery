// Delete Kth Element of Doubly Linked List
// Easy

// Hints
// Company
// Given the head of a doubly linked list and an integer k, remove the node at the kth position of the linked list and return the head of the modified list.

// Example 1

// Input: head = [2, 5, 7, 9], k = 2

// Output: head = [2, 7, 9]

// Explanation:

// The node with value 5 was removed.
// Example 2

// Input: head = [2, 5, 7], k = 1

// Output: head = [5, 7]

// Explanation:

// The node with value 2 was removed, note that the head was modified.

// Now your turn!

// Input: head = [2, 5, 7], k = 3

// Output:

// Correct

// head -> 5 <-> 7

// head -> 2 <-> 5

// head

// head -> 2 <-> 7
// Constraints

// n == Number of nodes in the linked list
// 1 <= n <= 100
// 0 <= ListNode.val <= 100
// 1 <= k <= n

// approach: Iterative
// Intuition
// We can iterate through the linked list to find the kth node and remove it by updating the pointers of the previous and next nodes. If k is 1, we need to update the head of the list to be the next node. If k is equal to the length of the list, we need to update the previous node's next pointer to be null. Otherwise, we update the previous node's next pointer to skip over the kth node and point to the kth node's next node, and we also update the next node's previous pointer to skip over the kth node and point to the kth node's previous node.

struct ListNode
{
    int data;
    ListNode *next;
    ListNode *prev;
    ListNode() : data(0), next(nullptr), prev(nullptr) {}
    ListNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *deleteKthElement(ListNode *head, int k)
    {
        if (!head)
            return nullptr; // if the list is empty, return nullptr

        if (k == 1)
        {
            ListNode *newHead = head->next; // if k is 1, update the head to be the next node
            if (newHead)
                newHead->prev = nullptr; // update the new head's previous pointer to be nullptr
            delete head;                 // delete the old head
            return newHead;              // return the new head
        }

        ListNode *current = head;
        for (int i = 1; i < k && current; i++)
        {
            current = current->next; // iterate to the kth node
        }

        if (!current)
            return head; // if k is greater than the length of the list, return the original head

        if (current->prev)
            current->prev->next = current->next; // update the previous node's next pointer

        if (current->next)
            current->next->prev = current->prev; // update the next node's previous pointer

        delete current; // delete the kth node
        return head;    // return the original head
    }
};