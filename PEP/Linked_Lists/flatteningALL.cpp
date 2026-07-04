// Flattening a Linked List
// Difficulty: MediumAccuracy: 51.53%Submissions: 242K+Points: 4Average Time: 40m
// Given a linked list containing n head nodes where every node in the linked list contains two pointers:
// (i) next points to the next node in the list.
// (ii) bottom points to a sub-linked list where the current node is the head.
// Each of the sub-linked lists nodes and the head nodes are sorted in ascending order based on their data. Flatten the linked list such that all the nodes appear in a single level while maintaining the sorted order.

// Note:
// 1. ↓ represents the bottom pointer and → represents the next pointer.
// 2. The flattened list will be printed using the bottom pointer instead of the next pointer.

// Examples:

// Input:

// Output: 5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 40 -> 45.
// Explanation:
// Bottom pointer of 5 is pointing to 7.
// Bottom pointer of 7 is pointing to 8.
// Bottom pointer of 10 is pointing to 20 and so on.
// So, after flattening the linked list the sorted list will be
// 5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 40 -> 45.
// Input:

// Output: 5 -> 7 -> 8 -> 10 -> 19 -> 22 -> 28 -> 30 -> 50
// Explanation:
// Bottom pointer of 5 is pointing to 7.
// Bottom pointer of 7 is pointing to 8.
// Bottom pointer of 8 is pointing to 30 and so on.
// So, after flattening the linked list the sorted list will be
// 5 -> 7 -> 8 -> 10 -> 19 -> 22 -> 28 -> 30 -> 50.
// Constraints:
// 0 ≤ n ≤ 100
// 1 ≤ number of nodes in sub-linked list(mi) ≤ 50
// 1 ≤ node->data ≤ 105

// approach:
// To flatten a linked list with multiple levels, we can use a recursive approach. The idea is to recursively flatten the next linked list and then merge it with the current linked list using the bottom pointers. We can use a helper function to merge two sorted linked lists. The base case for the recursion is when we reach the end of the linked list (i.e., when the next pointer is nullptr). At each step, we merge the current node's bottom list with the flattened next list, ensuring that the merged list remains sorted.

struct ListNode
{
    int data;
    ListNode *next;
    ListNode *bottom;
    ListNode() : data(0), next(nullptr), bottom(nullptr) {}
    ListNode(int val) : data(val), next(nullptr), bottom(nullptr) {}
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode *result = nullptr;

        if (l1->data < l2->data)
        {
            result = l1;
            result->bottom = mergeTwoLists(l1->bottom, l2);
        }
        else
        {
            result = l2;
            result->bottom = mergeTwoLists(l1, l2->bottom);
        }

        return result;
    }

    ListNode *flatten(ListNode *root)
    {
        if (!root || !root->next)
            return root;

        // Recursively flatten the next linked list
        root->next = flatten(root->next);

        // Merge the current linked list with the flattened next linked list
        root = mergeTwoLists(root, root->next);

        return root;
    }
};