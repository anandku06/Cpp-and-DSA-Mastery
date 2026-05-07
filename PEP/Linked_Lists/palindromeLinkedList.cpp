// 234. Palindrome Linked List
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

// Example 1:

// Input: head = [1,2,2,1]
// Output: true
// Example 2:

// Input: head = [1,2]
// Output: false

// Constraints:

// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 9

// Follow up: Could you do it in O(n) time and O(1) space?

// approach 1: using a array to store the values of the linked list and then checking if the array is a palindrome
// Time Complexity: O(n) for traversing the linked list and O(n) for checking if the array is a palindrome, resulting in an overall time complexity of O(n).
// Space Complexity: O(n) for storing the values of the linked list in the array.

// approach 2: using the fast and slow pointer technique to find the middle of the linked list, reverse the second half of the linked list and then compare the first half and the reversed second half of the linked list to check if it is a palindrome
// Time Complexity: O(n) for traversing the linked list and O(n) for comparing the two halves of the linked list, resulting in an overall time complexity of O(n).
// Space Complexity: O(1) for reversing the second half of the linked list and comparing the two halves of the linked list, resulting in an overall space complexity of O(1).

// approach 3: slight modification of approach 2, instead of reversing the second half of the linked list, we can compare the first half and the second half of the linked list while finding the middle of the linked list using the fast and slow pointer technique. This way we can avoid reversing the second half of the linked list and still check if it is a palindrome.

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
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true; // if head is nullptr or there is only one node in the list, then it is a palindrome

        ListNode *fast = head;    // fast pointer to find the middle of the linked list
        ListNode *slow = head;    // slow pointer to find the middle of the linked list
        ListNode *prev = nullptr; // previous pointer to reverse the second half of the linked list

        // find the middle of the linked list
        while (fast && fast->next)
        {
            fast = fast->next->next; // move the fast pointer two steps at a time

            // reverse the first half of the linked list while finding the middle
            ListNode *temp = slow->next; // store the next node of the slow pointer for updation
            slow->next = prev;           // reverse the link of the slow pointer to the previous node
            prev = slow;                 // move the previous pointer to the slow pointer
            slow = temp;                 // move the slow pointer to the next node
        }

        // if the number of nodes in the linked list is odd, then move the slow pointer one step ahead to skip the middle node
        if (fast)
            slow = slow->next;

        while (prev && slow)
        {
            if (prev->data != slow->data) // if the values of the nodes are not equal, then it is not a palindrome
                return false;

            prev = prev->next; // move the previous pointer to the next node in the reversed first half
            slow = slow->next; // move the slow pointer to the next node in the second half
        }

        return true; // if we have traversed both halves of the linked list and all values are equal, then it is a palindrome
    }
};

// approach 4: using recursion and backtracking to compare the first half and the second half of the linked list without reversing the second half of the linked list

class Solution2
{
public:
    ListNode *curr; // pointer to traverse the linked list from the beginning

    bool solve(ListNode *head)
    {
        if (head == nullptr)
            return true; // base case: if head is nullptr, then it is a palindrome

        // why? Agar kisi deeper level pe palindrome mismatch mil gaya aur false return hua, to upar wale recursive calls ko bhi immediately false return karna chahiye. Isliye, agar solve(head->next) false return karta hai, to hum directly false return kar denge bina aage ke code ko execute kiye.
        if (!solve(head->next))
            return false;

        if (head->data != curr->data) // recursive call to check the rest of the list and compare the current node's value with the value of the node pointed by curr
            return false;             // if the recursive call returns false or the values are not equal, then it is not a palindrome

        curr = curr->next; // move the curr pointer to the next node in the original order
        return true;       // if we have traversed the entire list and all values are equal, then it is a palindrome
    }

    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr)
            return true; // if head is nullptr, then it is a palindrome

        curr = head; // initialize the curr pointer to the head of the linked list
        return solve(head);
    }
};