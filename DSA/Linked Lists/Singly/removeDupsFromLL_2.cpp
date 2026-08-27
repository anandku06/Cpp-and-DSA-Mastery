// 82. Remove Duplicates from Sorted List II
// Medium
// Topics
// premium lock icon
// Companies
// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

// Example 1:

// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]
// Example 2:

// Input: head = [1,1,1,2,3]
// Output: [2,3]

// Constraints:

// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.

// approach: Iterative
// Intuition
// We can iterate through the linked list and check if the current node's value is equal to the next node's value. If they are equal, we can remove all the nodes with that value by updating the current node's next pointer to skip over all the nodes with that value and point to the next node with a different value. We continue this process until we reach the end of the linked list.

struct ListNode
{
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int val) : data(val), next(nullptr) {}
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return nullptr; // if the list is empty, return nullptr

        ListNode *dummy = new ListNode(0); // create a dummy node to handle edge cases
        dummy->next = head;                // point the dummy node's next pointer to the head of the list
        ListNode *prev = dummy;            // pointer to keep track of the previous node
        ListNode *curr = head;             // pointer to traverse the linked list

        while (curr)
        {
            // check if the current node's value is equal to the next node's value
            if (curr->next && curr->data == curr->next->data)
            {
                // skip all nodes with the same value
                while (curr->next && curr->data == curr->next->data)
                {
                    curr = curr->next;
                }
                prev->next = curr->next; // update the previous node's next pointer to skip over all nodes with the same value
            }
            else
            {
                prev = prev->next; // move the previous pointer to the current node
            }
            curr = curr->next; // move to the next node in the linked list
        }

        return dummy->next; // return the head of the modified linked list
    }
};