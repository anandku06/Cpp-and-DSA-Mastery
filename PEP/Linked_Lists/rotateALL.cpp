// 61. Rotate List
// Medium
// Topics
// premium lock icon
// Companies
// Given the head of a linked list, rotate the list to the right by k places.

// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Example 2:

// Input: head = [0,1,2], k = 4
// Output: [2,0,1]

// Constraints:

// The number of nodes in the list is in the range [0, 500].
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 109

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        // find the length of the linked list and the tail node
        ListNode *tail = head;
        int length = 1; // start with 1 since we are already at the head node
        while (tail->next != nullptr)
        {
            tail = tail->next;
            length++;
        }

        // connect the tail to the head to make it a circular linked list
        tail->next = head;

        // find the new tail node which will be at position (length - k % length) from the head
        int newTailPos = length - (k % length);
        ListNode *newTail = head;
        for (int i = 1; i < newTailPos; i++)
        {
            newTail = newTail->next;
        }

        // the new head will be the node after the new tail
        ListNode *newHead = newTail->next;

        // break the circular linked list
        newTail->next = nullptr;

        return newHead;
    }
};