// 148. Sort List
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given the head of a linked list, return the list after sorting it in ascending order.

// Example 1:

// Input: head = [4,2,1,3]
// Output: [1,2,3,4]
// Example 2:

// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]
// Example 3:

// Input: head = []
// Output: []

// Constraints:

// The number of nodes in the list is in the range [0, 5 * 104].
// -105 <= Node.val <= 105

// Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

// approach: using Merge Sort logic, initialise dummy node, then comparing each node's value and appending in the new linked list, if any of the list remains, just append at the last

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
    ListNode *mergeSortedList(ListNode *head1, ListNode *head2)
    {
        if (head1 == nullptr)
            return head2;
        if (head2 == nullptr)
            return head1;

        ListNode *dum = new ListNode();
        ListNode *temp = dum;

        while (head1 && head2)
        {
            if (head1->data <= head2->data)
            {
                temp->next = head1;
                head1 = head1->next;
            }
            else
            {
                temp->next = head2;
                head2 = head2->next;
            }
        }

        if (head1)
            temp->next = head1;
        else
            temp->next = head2;

        return dum->next; // return the next of dummy node, as dummy node is just a placeholder
    }

    ListNode *getMiddle(ListNode *head)
    {
        if (!head)
            return head;

        ListNode *slow = head;
        ListNode *fast = head->next; // fast pointer starts from the second node, bcz we want to get the middle node, if we start from the first node, then in case of even number of nodes, we don't want the second middle node, we want the first middle node, so we start from the second node

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode *sortList(ListNode *head)
    {
        // Base case: if the list is empty or has only one node, it's already sorted
        if (!head || !head->next)
            return head;

        // middle node
        ListNode *middle = getMiddle(head);

        ListNode *right = middle->next;
        middle->next = nullptr;

        // Recursively sort both halves
        ListNode *left = sortList(head);
        right = sortList(right);

        // Merge the sorted halves
        return mergeSortedList(left, right);
    }
};