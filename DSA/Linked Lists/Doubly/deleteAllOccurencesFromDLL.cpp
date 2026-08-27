// Delete All Occurrences in DLL
// Solved
// Difficulty: MediumAccuracy: 50.04%Submissions: 86K+Points: 4Average Time: 30m
// You are given the head of a doubly Linked List and a key x . Your task is to delete all occurrences of the given key x if it is present and return the new DLL.

// Examples:

// Input: 2<->2<->10<->8<->4<->2<->5<->2, x = 2

// Output:  10<->8<->4<->5

// Explanation:
// All Occurrences of 2 have been deleted.
// Input: head = 9<->1<->3<->4<->5<->1<->8<->4, x = 9

// Output: 1<->3<->4<->5<->1<->8<->4

// Explanation:
// All Occurrences of 9 have been deleted.
// Constraints:

// 1 ≤ size of linked list ≤ 105
// 0 ≤ node.data ≤ 109

struct ListNode
{
    int data;
    ListNode *next;
    ListNode *prev;
    ListNode() : data(0), next(nullptr), prev(nullptr) {}
    ListNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *deleteAllOccurOfX(ListNode *head, int x)
    {
        ListNode *curr = head; // pointer to traverse the linked list

        while (curr)
        {
            // if the current node's data is equal to x, then we need to delete the current node
            if (curr->data == x)
            {
                if (curr == head)
                {
                    head = curr->next;
                }

                ListNode *front = curr->next;
                ListNode *back = curr->prev;

                if (front)
                {
                    front->prev = back;
                }
                if (back)
                {
                    back->next = front;
                }

                curr = front;
            }
            else
                curr = curr->next;
        }

        return head;
    }
};