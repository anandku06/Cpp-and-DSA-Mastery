// 23. Merge k Sorted Lists
// Hard
// Topics
// premium lock icon
// Companies
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted linked list:
// 1->1->2->3->4->4->5->6
// Example 2:

// Input: lists = []
// Output: []
// Example 3:

// Input: lists = [[]]
// Output: []

// Constraints:

// k == lists.length
// 0 <= k <= 104
// 0 <= lists[i].length <= 500
// -104 <= lists[i][j] <= 104
// lists[i] is sorted in ascending order.
// The sum of lists[i].length will not exceed 104.

// approach : we can use a min heap to store the first element of each linked list, and we can pop the minimum element from the heap and add it to the result linked list, and if the popped element has a next element, then we can push the next element to the heap, and we can repeat this process until the heap is empty.
// time complexity : O(n log k) where n is the total number of elements in all the linked lists and k is the number of linked lists, and space complexity : O(k) for the heap.

// approach : we can use a divide and conquer approach to merge the linked lists, we can merge the first two linked lists and then merge the result with the third linked list and so on until we have merged all the linked lists, and we can use the merge function of the merge sort algorithm to merge two linked lists.
// time complexity : O(n log k) where n is the total number of elements in all the linked lists and k is the number of linked lists, and space complexity : O(1) for the merge function.

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        if (l1->data <= l2->data)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }

        return nullptr;
    }

    ListNode *partitionAndMerge(vector<ListNode *> &lists, int left, int right)
    {
        if (left >= right)
            return nullptr; // base case: if there are no linked lists, return nullptr
        if (left == right)
            return lists[left]; // base case: if there is only one linked list, return it

        int mid = left + (right - left) / 2;                     // find the middle index of the linked lists
        ListNode *L1 = partitionAndMerge(lists, left, mid);      // recursively merge the left half of the linked lists
        ListNode *L2 = partitionAndMerge(lists, mid + 1, right); // recursively merge the right half of the linked lists
        return mergeTwoLists(L1, L2);                            // merge the two merged linked lists and return the result
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;

        int n = lists.size();

        return partitionAndMerge(lists, 0, n - 1); // merge all the linked lists and return the result
    }
};