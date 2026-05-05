// 206. Reverse a Linked List

// Given the head of a singly linked list, reverse the list, and return the reversed list.

// Example 1:

// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]
// Example 2:

// Input: head = [1,2]
// Output: [2,1]
// Example 3:

// Input: head = []
// Output: []

// approach: Take two pointers, prev and curr, prev to nullptr and curr to the head, loop until curr is nullptr (end of the list), and curr->next updating to prev and updating the curr and prev simultaneously

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;

    ListNode(int val) : data(val), next(nullptr) {}
};

class Solution
{
public:
    ListNode *reverseALinkedList(ListNode *head)
    {
        if (head == nullptr)
            return head; // if head is nullptr, then return the head as it is

        ListNode *curr = head;    // current pointer
        ListNode *prev = nullptr; // previous pointer

        while (curr != nullptr)
        {
            ListNode *temp = curr->next; // storing the next node for updation

            curr->next = prev; // reversing the link to prev
            prev = curr;       // updating the prev to curr
            curr = temp;       // updating curr to next node
        }

        return prev; // because prev will take the place of curr pointer
    }
};

// approach 2: using recursion, we can reverse the linked list by recursively calling the function on the next node until we reach the end of the list, and then reversing the links while backtracking

class Solution2
{
public:
    ListNode *reverseALinkedList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head; // if head is nullptr or there is only one node in the list, then return the head as it is

        ListNode *newHead = reverseALinkedList(head->next); // recursively reverse the rest of the list and get the new head of the reversed list

        head->next->next = head; // reverse the link of the current node to point to itself
        head->next = nullptr;    // set the next pointer of the current node to nullptr to terminate the list

        return newHead; // return the new head of the reversed list
    }
};