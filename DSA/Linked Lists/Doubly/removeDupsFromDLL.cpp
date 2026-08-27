// Remove duplicates from sorted DLL
// hard

// Hints
// Company
// Given the head of a doubly linked list with its values sorted in non-decreasing order. Remove all duplicate occurrences of any value in the list so that only distinct values are present in the list.

// Return the head of the modified linked list.

// Example 1

// Input: head -> 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5

// Output: head -> 1 <-> 3 <-> 4 <-> 5

// Explanation: head -> 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5

// The underlined nodes were deleted to get the desired result.

// Example 2

// Input: head -> 1 <-> 1 <-> 1 <-> 1 <-> 1 <-> 2

// Output: head -> 1 <-> 2

// Explanation: head -> 1 <-> 1 <-> 1 <-> 1 <-> 1 <-> 2

// The underlined nodes were deleted to get the desired result.

// Now your turn!

// Input: head -> 1 <-> 2 <-> 3

// Output:

// Incorrect

// head -> 1 -> 2 -> 3

// head -> 1 <-> 1 <-> 2 <-> 3

// head -> 1 <-> 2 <-> 3

// head -> 3 <-> 2 <-> 1
// Constraints

// 1 <= number of nodes in the linked list <= 105
// -104 <= ListNode.val <= 104
// Values of nodes are sorted in non-decreasing order.

// approach: Iterative
// Intuition
// We can iterate through the linked list and check if the current node's value is equal to the next node's value. If they are equal, we can remove the next node by updating the current node's next pointer to skip over the next node and point to the next node's next node, and we also update the next node's next node's previous pointer to skip over the next node and point to the current node. We continue this process until we reach the end of the linked list.

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
    ListNode *removeDuplicates(ListNode *head)
    {
        if (!head)
            return nullptr; // if head is nullptr, then return nullptr

        ListNode *curr = head; // pointer to traverse the linked list

        while (curr && curr->next)
        {
            if (curr->data == curr->next->data)
            {                                  // if the current node's value is equal to the next node's value, then we need to remove the next node
                ListNode *temp = curr->next;   // store the next node in a temporary pointer
                curr->next = curr->next->next; // point the current node's next pointer to the next node's next node

                if (curr->next)
                { // if the current node's next pointer is not nullptr, then we need to update the next node's previous pointer to point to the current node
                    curr->next->prev = curr;
                }

                delete temp; // delete the next node
            }
            else
            { // if the current node's value is not equal to the next node's value, then we can move to the next node
                curr = curr->next;
            }
        }
        return head;
    }
};