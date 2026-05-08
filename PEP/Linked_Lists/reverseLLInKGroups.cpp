// 25. Reverse Nodes in k-Group
// Hard
// Topics
// premium lock icon
// Companies
// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]
// Example 2:

// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]

// Constraints:

// The number of nodes in the list is n.
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000

// Follow-up: Can you solve the problem in O(1) extra memory space?

// approach:
// First, traverse the linked list to identify segments of K nodes. For each segment, adjust the pointers within the segment to reverse the direction of the nodes. This involves iterating through the segment and changing the links between nodes.

// Next, after reversing a segment, connect the reversed segment to the previous part of the list. Continue this process until you reach the end of the list.

// Finally, if there are fewer than K nodes left at the end of the list, leave them as they are. Return the head of the modified linked list.

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
    ListNode *reverseLinkedList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *newHead = reverseLinkedList(head->next);

        head->next->next = head; // reversing the link to the next node
        head->next = nullptr;    // setting the next of current node to nullptr

        return newHead; // returning the new head of the reversed linked list
    }

    ListNode *getKthNode(ListNode *head, int k)
    {
        ListNode *curr = head;
        for (int i = 1; i < k && curr != nullptr; i++)
        {
            curr = curr->next;
        }
        return curr; // returns the kth node or nullptr if there are less than k nodes
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;        // temporary pointer to traverse the list
        ListNode *prevTail = nullptr; // pointer to keep track of the tail of the previous reversed segment

        while (temp)
        {
            ListNode *kthNode = getKthNode(temp, k); // get the kth node from the current position

            // if there are less than k nodes left, then we can break the loop and return the head of the modified list
            if (kthNode == nullptr)
            {
                if (prevTail)
                {
                    prevTail->next = temp; // connect the last reversed segment to the remaining nodes
                }
                break;
            }

            ListNode *nextSegmentHead = kthNode->next; // store the head of the next segment
            kthNode->next = nullptr;                   // disconnect the current segment from the next segment

            reverseLinkedList(temp); // reverse the current segment

            if (temp == head) // if we are reversing the first segment, then we need to update the head of the modified list
            {
                head = kthNode; // update the head to the new head of the reversed segment
            }
            else
            {
                prevTail->next = kthNode; // connect the previous segment to the new head of the reversed segment
            }

            prevTail = temp;        // update the prevTail to the tail of the current reversed segment
            temp = nextSegmentHead; // move to the next segment
        }

        return head; // return the head of the modified linked list
    }
};