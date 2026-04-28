# Sliding Window

- The sliding window technique, when combined with the two-pointer approach, is a powerful method for solving problems that involve subarrays or substrings within a fixed range.
- The constant window approach maintains a window of a specific size and slides it across the array or string. This editorial details a method to efficiently compute the sum of elements within such a window by leveraging the properties of the sliding window technique.

## Constant Window Size

### Steps

- Initialize two pointers: left and right. The left pointer marks the beginning of the window, and the right pointer marks the end.
- Calculate the sum of the initial window.
- Slide the window by incrementing both left and right pointers. Update the sum by subtracting the element at the left pointer and adding the element at the right pointer.
- Continue this process until the window has traversed the entire array.

```cpp
#include<bits/stdc++.h>
using namespace std;

void slidingWindowSum(const vector<int>& arr, int k) {
    int n = arr.size();
    int sum = 0;

    // Calculate the sum of the initial window
    for (int i = 0; i < k; ++i) {
        sum += arr[i];
    }

    // Print the sum of the first window
    cout << "Sum of window 1: " << sum << endl;

    // Slide the window across the array
    for (int i = k; i < n; ++i) {
        sum = sum - arr[i - k] + arr[i]; // Update the sum
        cout << "Sum of window " << i - k + 2 << ": " << sum << endl;
    }
}

int main() {
    vector<int> arr = {1, 3, 2, 6, 4, 8, 5};
    int k = 3;
    slidingWindowSum(arr, k);
    return 0;
}

```

### Variations

- **Variable Window Size**: Instead of maintaining a constant window size, the window can expand or contract based on certain conditions (e.g., sum exceeds a target value).
- **Maximum/Minimum in Window**: Instead of calculating the sum, we can maintain the maximum or minimum element in the current window using a deque or priority queue.
- **Count of Distinct Elements**: We can use a hash map to count the frequency of elements in the current window and maintain the count of distinct elements.
- **Longest Substring Without Repeating Characters**: This is a common problem where we use a sliding window to find the longest substring that contains no duplicate characters.

### Time Complexity

- The time complexity of the sliding window technique is O(n) for most problems, as each element is processed at most twice (once when it enters the window and once when it leaves). This makes it an efficient approach for solving a wide range of problems involving subarrays or substrings.

## Variable Window Size

### Steps

- Initialize Pointers: Start with two pointers, L (left) and R (right), both set to the beginning of the array or string. Also, initialize variables sum and maxLength to zero.
- Expand the Window: Start expanding the window by moving the R pointer. Add the element at the R pointer to sum.
- Check the Condition: If the sum is less than or equal to K, check if the current window size (R - L + 1) is the largest so far. If it is, update maxLength.
- Shrink the Window: If the sum exceeds K, start shrinking the window by moving the L pointer to the right. Subtract the element at the L pointer from sum and continue this process until the sum is less than or equal to K again.
- Continue Until the End: Repeat the above steps until the R pointer reaches the end of the array or string.
- Result: The value in maxLength at the end of the process will be the length of the longest subarray or substring that satisfies the condition.

```cpp
#include<bits/stdc++.h>
using namespace std;

// Function to find the longest subarray with sum <= K
int longestSubarrayWithSum(vector<int>& arr, int K) {
    int n = arr.size();
    int maxLength = 0; // Initialize the maximum length to 0
    int sum = 0;       // Initialize the current sum to 0
    int left = 0;      // Left pointer for the sliding window

    // Iterate over the array using the right pointer
    for (int right = 0; right < n; right++) {
        sum += arr[right]; // Add the current element to the sum

        // Shrink the window from the left if sum exceeds K
        while (sum > K) {
            sum -= arr[left]; // Subtract the leftmost element from the sum
            left++;           // Move the left pointer to the right
        }
        // Update the maximum length if the current window is valid
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength; // Return the maximum length of the valid subarray
}

int main() {
    vector<int> arr = {2, 5, 1, 7, 10}; // Example array
    int K = 14; // Example value of K

    // Find and print the length of the longest subarray with sum <= K
    int result = longestSubarrayWithSum(arr, K);
    cout << "The longest subarray length with sum <= " << K << " is: " << result << endl;

    return 0;
}
```

### Variations

- **Longest Substring with At Most K Distinct Characters**: Use a hash map to count the frequency of characters in the current window and maintain the count of distinct characters.
- **Longest Substring with At Most K Repeating Characters**: Similar to the above, but instead of counting distinct characters, count the frequency of each character and ensure that no character exceeds K occurrences.
- **Longest Subarray with Sum Exactly K**: Instead of checking if the sum is less than or equal to K, check if it is exactly K. This may require a different approach, such as using a hash map to store the cumulative sum at each index.

### Time Complexity

- The time complexity of the variable window size approach is O(n) in the average case, as each element is processed at most twice (once when it enters the window and once when it leaves). However, in the worst case, it can be O(n^2) if the window needs to be shrunk frequently.

## Counting The Number of Subarrays with Sum

- Consider the problem of counting the number of subarrays that sum up to 'k'.
- The approach involves calculating the number of subarrays with at most K ones and then subtracting the number of subarrays with at most K-1 ones.
- The difference gives the number of subarrays with exactly K ones.

### Steps

- Define a helper function that counts the number of subarrays with at most K ones. If K is less than 0, the result is 0.
- Iterate through the array using two pointers. Adjust the window size to ensure the sum of the window is at most K. Incrementally add the number of valid subarrays to the result.
- Subtract the result of atMost(K-1) from atMost(K) to get the number of subarrays with exactly K ones.

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the number of subarrays with exactly sum S
    int numSubarraysWithSum(vector<int>& A, int S) {
        return atMost(A, S) - atMost(A, S - 1);
    }

private:
    // Helper function to find the number of subarrays with at most sum S
    int atMost(vector<int>& A, int S) {
        if (S < 0) return 0;
        int res = 0, i = 0;

        // Sliding window approach to count subarrays
        for (int j = 0; j < A.size(); j++) {
        // Include A[j] in the current window
            S -= A[j];
            while (S < 0) {
            // Shrink the window if the sum exceeds S
                S += A[i++];
            }
           // Count all subarrays ending at j
            res += j - i + 1;
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> A = {1, 0, 1, 0, 1}; // Example array
    int S = 2; // Desired sum
    int result = sol.numSubarraysWithSum(A, S);
    cout << "Number of subarrays with sum " << S << ": " << result << endl;
    return 0;
}
```
