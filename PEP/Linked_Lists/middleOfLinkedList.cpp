// 876. Middle of the Linked List

// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

 

// Example 1:


// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.
// Example 2:


// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

// approach: Initialise two pointers, fast that moves two steps at a time, and one slow that moves one step.
//              if, fast or fast->next moves to the end of the list (nullptr), then slow has to be on the middle

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val): data(val), next(nullptr) {}
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        ListNode* middleOfTheLinkedList(ListNode* head) {
            if(!head) return head;

            ListNode* fast = head;
            ListNode* slow = head;

            while (fast && fast->next)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            
            return slow;
        }
};