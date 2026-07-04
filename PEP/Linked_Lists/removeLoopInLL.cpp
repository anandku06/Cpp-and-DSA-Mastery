// Remove loop in Linked List
// Difficulty: MediumAccuracy: 27.66%Submissions: 560K+Points: 4Average Time: 45m
// Given the head of a singly linked list, the task is to remove a cycle if present. A cycle exists when a node's next pointer points back to a previous node, forming a loop.

// Internally, a variable pos is used to denotes the position of the node where the cycle starts, but it is not passed as a parameter.
// The linked list remains as it is if there is cycle in the list.
// The output will be "true" if your code works according to expectations, otherwise "false".
// Examples:

// Input: head = 1 -> 3 -> 4, pos = 2
// Output: true
// Explanation: The linked list looks like

// A loop is present in the list, and it is removed.
// Input: head = 1 -> 8 -> 3 -> 4, pos = 0
// Output: true
// Explanation:

// The Linked list does not contains any loop.
// Input: head = 1 -> 2 -> 3 -> 4, pos = 1
// Output: true
// Explanation: The linked list looks like

// A loop is present in the list, and it is removed.
// Constraints:
// 1 ≤ size of linked list ≤ 105

// approach:
// To remove a loop in a linked list, we can use Floyd's Cycle Detection Algorithm (also known as the Tortoise and Hare algorithm). The algorithm involves two pointers, a slow pointer and a fast pointer. The slow pointer moves one step at a time, while the fast pointer moves two steps at a time. If there is a loop in the linked list, the fast pointer will eventually meet the slow pointer. Once a loop is detected, we can find the starting point of the loop and remove it by setting the next pointer of the last node in the loop to nullptr.

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
    void removeLoop(ListNode *head)
    {
        if (!head || !head->next)
            return;

        ListNode *slow = head;
        ListNode *fast = head;

        // Step 1: Detect loop
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                break;
            }
        }

        // If no loop was detected, return
        if (slow != fast)
            return;

        // Step 2: Find the starting point of the loop
        slow = head;

        // EDGE CASE: If the loop starts at the head node
        if (slow == fast)
        {
            while (fast->next != slow)
            {
                fast = fast->next;
            }
            fast->next = nullptr; // Break the loop
            return;
        }

        // Standard Case: If the loop starts somewhere in the middle
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // Step 3: Remove the loop
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = nullptr;
    }
};