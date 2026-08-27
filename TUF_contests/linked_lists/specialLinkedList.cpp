// Special Linked List
// Medium

// Given the head of Linked List and an integer val, partition the list as a special Linked List.

// A special linked list is one in which all nodes with values less than val come before all nodes equal to or greater than val. You have to keep the relative ordering of the nodes within the partition the same as the initial list.

// Example 1

// Input: head -> 5 -> 2 -> 4 -> 1 -> 3 -> 4, val = 3

// Output: head -> 2 -> 1 -> 5 -> 4 -> 3 -> 4

// Explanation: head -> 5 -> 2 -> 4 -> 1 -> 3 -> 4

// The underlined nodes are less than val, so they come before others.

// Note that the ordering of elements within the group is maintained.

// Example 2

// Input: head -> 3 -> 7 -> 2 -> 5 -> 3 -> 1, val = 4

// Output: head -> 3 -> 2 -> 3 -> 1 -> 7 -> 5

// Explanation: head -> 3 -> 7 -> 2 -> 5 -> 3 -> 1

// Constraints

// 1 <= Number of Nodes in the Linked List <= 105
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
    ListNode *partitionList(ListNode *head, int val)
    {
        ListNode *greatHead = new ListNode();
        ListNode *lessHead = new ListNode();

        ListNode *temp = head;
        ListNode *g = greatHead;
        ListNode *l = lessHead;

        while (temp)
        {
            if (temp->data < val)
            {
                l->next = temp;
                l = l->next;
            }
            else
            {
                g->next = temp;
                g = g->next;
            }

            temp = temp->next;
        }

        l->next = greatHead->next;
        g->next = nullptr;

        return lessHead->next;
    }
};