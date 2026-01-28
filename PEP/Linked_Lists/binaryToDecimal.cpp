// 1290. Convert Binary Number in Linked List to Decimal

// Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

// Return the decimal value of the number in the linked list.

// The most significant bit is at the head of the linked list.

// Example 1:

// Input: head = [1,0,1]
// Output: 5
// Explanation: (101) in base 2 = (5) in base 10
// Example 2:

// Input: head = [0]
// Output: 0

// approach: by left shifting each bit by 1 (multiplying by 2), and adding to the current head value

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
    int convertBinaryToDecimal(ListNode *head)
    {
        int num = 0;

        if (!head)
            return num;

        while (head)
        {
            num = num << 1 | head->data; // left shift by 1 and OR the current head value
            head = head->next;
        }
        return num;
    }
};