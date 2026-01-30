// 21. Mergw Two Sorted Linked List

// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

// Example 1:

// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// Example 2:

// Input: list1 = [], list2 = []
// Output: []
// Example 3:

// Input: list1 = [], list2 = [0]
// Output: [0]

// approach: using Merge Sort logic, initialise dummy node, then comparing each node's value and appending in the new linked list, if any of the list remains, just append at the last

struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int val) : data(val), next(nullptr) {}
    ListNode() : data(0), next(nullptr) {}
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *mergeSortedList(ListNode *head1, ListNode *head2)
    {
        if (head1 == nullptr)
            return head2;
        if (head2 == nullptr)
            return head1;

        ListNode *dum = new ListNode();
        ListNode *temp = dum;

        ListNode *p1 = head1;
        ListNode *p2 = head2;

        while (p1 && p2)
        {
            if (p1->data <= p2->data)
            {
                temp->next = new ListNode(p1->data);
                p1 = p1->next;
            }
            else
            {
                temp->next = new ListNode(p2->data);
                p2 = p2->next;
            }

            temp = temp->next;
        }

        // if p1 or p2 are not null so just append either of them
        if (p1)
            temp->next = p1;
        if (p2)
            temp->next = p2;

        ListNode *head = dum->next;
        delete dum;

        return head;
    }
};