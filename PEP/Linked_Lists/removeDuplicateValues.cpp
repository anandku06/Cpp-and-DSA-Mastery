// 83. Remove Duplicates in a Linked List

// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

// Example 1:


// Input: head = [1,1,2]
// Output: [1,2]
// Example 2:


// Input: head = [1,1,2,3,3]
// Output: [1,2,3]


// approach is the skip the same node, i.e. checking whether the current node's value is same as of next node, If yes then connect the node to next of next node

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
    ListNode *removeDuplicates(ListNode *head)
    {
        if (!head)
            return head;

        ListNode *temp = head;

        while (head && head->next)
        {
            if (head->data == head->next->data)
            {
                head->next = head->next->next;
            }
            else
                head = head->next;
        }

        return temp;
    }
};