// 24. Swap nodes of a Linked List

// Given an integer n, return true if it is a power of three. Otherwise, return false.

// An integer n is a power of three, if there exists an integer x such that n == 3x.

 

// Example 1:

// Input: n = 27
// Output: true
// Explanation: 27 = 33
// Example 2:

// Input: n = 0
// Output: false
// Explanation: There is no x where 3x = 0.
// Example 3:

// Input: n = -1
// Output: false
// Explanation: There is no x where 3x = (-1).

// approach : traversing with three pointers and changing the next pointers as we are traversing

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val): data(val), next(nullptr) {}
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        ListNode* swapNodesOfLinkedList(ListNode* head) {
            if(!head || !head->next) return head;

            ListNode* temp = head;
            ListNode* newhead = nullptr;
            ListNode* prev = nullptr;

            while (temp && temp->next)
            {
                ListNode* left = temp;
                ListNode* right = temp->next;
                ListNode* ahead = right->next;

                if(!newhead) newhead = right;

                left->next = ahead;
                right->next = left;

                if(prev) prev->next = right;

                prev = left;
                temp = ahead;
            }

            return newhead;
            
        }
};