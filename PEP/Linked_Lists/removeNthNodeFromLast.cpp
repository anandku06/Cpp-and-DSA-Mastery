// 19. Remove Nth Node From End of List
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Example 1:

// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:

// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]

// Constraints:

// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz

// Follow up: Could you do this in one pass?

// 2 pass solution: find the length of the linked list and then remove the nth node from the end of the linked list

struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int val) : data(val), next(nullptr) {}
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr)
            return nullptr; // if head is nullptr, then return nullptr

        int len = 0;           // variable to store the length of the linked list
        ListNode *temp = head; // temporary pointer to traverse the linked list

        // find the length of the linked list
        while (temp != nullptr)
        {
            len++;
            temp = temp->next;
        }

        // if n is equal to the length of the linked list, then we need to remove the head node
        if (n == len)
            return head->next; // return the next node of the head node as the new head of the linked list

        temp = head; // reset the temporary pointer to the head of the linked list
        // traverse the linked list until we reach the node just before the node to be removed
        for (int i = 1; i < len - n; i++)
        {
            temp = temp->next;
        }

        // remove the nth node from the end of the linked list by changing the next pointer of the node just before the node to be removed
        temp->next = temp->next->next;
        return head; // return the head of the modified linked list
    }
};

// 1 Pass solution: using two pointers, we can maintain a gap of n nodes between the two pointers and then move both pointers until the second pointer reaches the end of the linked list. At this point, the first pointer will be pointing to the node just before the node to be removed, and we can remove the nth node from the end of the linked list by changing the next pointer of the first pointer.

class Solution2
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr)
            return nullptr; // if head is nullptr, then return nullptr

        ListNode *first = head;  // first pointer to maintain the gap of n nodes
        ListNode *second = head; // second pointer to traverse the linked list

        // move the second pointer n nodes ahead of the first pointer
        for (int i = 0; i < n; i++)
        {
            first = first->next;
        }

        // if first pointer is nullptr, it means we need to remove the head node
        if (first == nullptr)
            return head->next; // return the next node of the head node as the new head of the linked list

        // move both pointers until the first pointer reaches the end of the linked list
        while (first->next != nullptr)
        {
            first = first->next;
            second = second->next;
        }

        // remove the nth node from the end of the linked list by changing the next pointer of the second pointer
        second->next = second->next->next;
        return head; // return the head of the modified linked list
    }
};