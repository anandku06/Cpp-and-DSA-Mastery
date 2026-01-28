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
    ListNode* next;

    ListNode(int val) : data(val), next(nullptr) {}
};


class Solution {
    public:
        ListNode* reverseALinkedList(ListNode* head) {
            if(head == nullptr) return head; // if head is nullptr, then return the head as it is
            
            ListNode* curr = head; // current pointer
            ListNode* prev = nullptr; // previous pointer

            while (curr != nullptr)
            {
                ListNode* temp = curr->next; // storing the next node for updation

                curr->next = prev; // reversing the link to prev
                prev = curr; // updating the prev to curr
                curr = temp; // updating curr to next node
            }
            
            return prev; // because prev will take the place of curr pointer
        }
};