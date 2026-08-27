// Remove bad elements in Linked List
// Easy

// Given the head of a Linked List and an integer val, remove all nodes having value val and return the head of the modified list.

// Example 1

// Input: head -> 3 -> 4 -> 1 -> 3 -> 5 -> 7, val = 3

// Output: head -> 4 -> 1 -> 5 -> 7

// Explanation: The nodes with value 3 were removed.

// Example 2

// Input: head -> 1 -> 2 -> 4 -> 5 -> 3 -> 7, val = 7

// Output: head -> 1 -> 2 -> 4 -> 5 -> 3

// Explanation: The node with value 7 was removed.

// Constraints

// 1 <= Number of nodes in the Linked List <= 105
// -104 <= ListNode.val <= 104
// -104 <= val <= 104

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
    ListNode *removeBadElements(ListNode *head, int val)
    {
        ListNode *dum = new ListNode(0, head);
        ListNode *curr = head;
        ListNode *prev = dum;

        while (curr)
        {
            if (curr->val == val)
            {
                prev->next = curr->next;
            }
            else
                prev = curr;

            curr = curr->next;
        }

        return dum->next;
    }
};