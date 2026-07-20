// Allocate Minimum Pages
// Difficulty: MediumAccuracy: 35.51%Submissions: 423K+Points: 4Average Time: 35m
// Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// All books must be allocated.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum. If it is not possible to allocate books to all students, return -1;

// Note: Test cases are generated such that the answer always fits in a 32-bit integer.

// Examples:

// Input: arr[] = [12, 34, 67, 90], k = 2
// Output: 113
// Explanation: Allocation can be done in following ways:
// => [12] and [34, 67, 90] Maximum Pages = 191
// => [12, 34] and [67, 90] Maximum Pages = 157
// => [12, 34, 67] and [90] Maximum Pages = 113.
// The third combination has the minimum pages assigned to a student which is 113.
// Input: arr[] = [15, 17, 20], k = 5
// Output: -1
// Explanation: Since there are more students than total books, it's impossible to allocate a book to each student.
// Constraints:
// 1 ≤ arr.size() ≤ 106
// 1 ≤ arr[i], k ≤ 104

// Approach: Binary Search
// Intuition
// The problem can be solved using a binary search approach. We can define a function that checks if it is possible to allocate books to students such that the maximum number of pages assigned to any student is at most a given value. We can then use binary search to find the minimum possible maximum number of pages.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &arr, int n, int k, long long mid)
    {
        int studentsRequired = 1; // Start with one student
        long long currentSum = 0; // Current sum of pages assigned to the current student

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mid)
                return false; // If a single book has more pages than mid, allocation is not possible

            if (currentSum + arr[i] > mid)
            {
                // If adding this book exceeds mid, allocate to next student
                studentsRequired++;
                currentSum = arr[i]; // Start counting pages for the new student
            }
            else
            {
                currentSum += arr[i]; // Add pages to the current student's total
            }
        }

        return studentsRequired <= k; // Check if we can allocate within k students
    }

    int findPages(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (k > n)
            return -1; // If there are more students than books, return -1

        long long sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i]; // Calculate the total number of pages

        // why we are taking max_element as low because the minimum possible maximum pages that can be assigned to a student is the maximum number of pages in a single book. If we try to assign less than that, it would be impossible to allocate that book to any student. Hence, we start our binary search from the maximum single book's pages.

        long long low = *max_element(arr.begin(), arr.end()); // The minimum possible maximum pages is the maximum single book
        long long high = sum;                                 // The maximum possible maximum pages is the total number of pages

        // why we are taking sum as high because the maximum possible maximum pages that can be assigned to a student is the total number of pages in all books. If we assign all books to one student, that student will have to read all the pages, which is equal to the sum of all pages. Hence, we set our binary search upper limit to the total sum of pages.
        long long result = high; // Initialize result to the highest possible value

        while (low <= high)
        {
            long long mid = low + (high - low) / 2; // Find the mid value
            if (isPossible(arr, n, k, mid))
            {
                result = mid; // If it's possible to allocate with this max, try for a smaller max
                high = mid - 1;
            }
            else
            {
                low = mid + 1; // If not possible, increase the max limit
            }
        }

        return result;
    }
};