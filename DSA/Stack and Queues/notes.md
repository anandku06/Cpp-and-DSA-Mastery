# Monotonic DS

- One of the most powerful techniques in solving problems related to stacks and queues is the concept of a monotonic data structure. A monotonic data structure is a data structure that maintains its elements in a specific order, either increasing or decreasing.
- This allows us to efficiently solve problems that require us to find the next greater or smaller element for each element in an array.

Questions like:

- Next Greater Element/ Next Smaller Element
- Sliding Window Maximum/ Minimum
- Finding min/max in dynamic ranges
- stock span problems
  etc. can be solved using monotonic data structures.

- In mathematics, a monotonic function is a function that is either non-increasing or non-decreasing. Similarly, in data structures, a monotonic data structure is one that maintains its elements in a specific order, either increasing or decreasing.
- We often use this idea in stacks and queues to maintain a certain order of elements, which allows us to efficiently solve problems that require us to find the next greater or smaller element for each element in an array.

## Monotonic Stack

- A monotonic stack is a stack that maintains its elements in a specific order, either increasing or decreasing.

### Monotonic Increasing Stack

- A monotonic increasing stack is a stack that maintains its elements in increasing order.
- This means that the top of the stack will always be the smallest element in the stack.
- When we push a new element onto the stack, we will pop all the elements from the stack that are greater than the new element until we find an element that is smaller than or equal to the new element. This way, we maintain the increasing order of the elements in the stack.

```cpp
// Example of a monotonic increasing stack

// We will use a stack to keep track of the indices of the elements in the array.
// We will iterate through the array and for each element, we will pop the elements from the stack until we find an element that is smaller than or equal to the current element.

stack<int> st; // stack to keep track of the indices of the elements in the array
for (int i = 0; i < nums.size(); i++) {
    while (!st.empty() && nums[st.top()] > nums[i]) {
        st.pop(); // pop the indices of the elements that are greater than the current element
    }
    st.push(i);
}

```

#### Next Smaller Element (Left)

- Brute Force: O(n^2) -> For each element, we will iterate through the array to find the next smaller element.
- Monotonic Stack: O(n) -> We will use a monotonic increasing stack to find the next smaller element for each element in the array. We will iterate through the array and for each element, we will pop the elements from the stack until we find an element that is smaller than or equal to the current element. The popped elements will have the current element as their next smaller element.

```cpp
vector<int> nextSmallerElement(vector<int>& nums) {
    vector<int> result(nums.size(), -1); // initialize the result vector with -1
    stack<int> st; // stack to keep track of the indices of the elements in the array
    for (int i = 0; i < nums.size(); i++) {
        while (!st.empty() && nums[st.top()] > nums[i]) {
            result[st.top()] = nums[i]; // the popped element will have the current element as its next smaller element
            st.pop(); // pop the indices of the elements that are greater than the current element
        }
        st.push(i);
    }
    return result;
}
```

#### Next Smaller Element (Right)

- Just iterate from the end of the array and do the same as above. The popped elements will have the current element as their next smaller element.

```cpp
vector<int> nextSmallerElementRight(vector<int>& nums) {
    vector<int> result(nums.size(), -1); // initialize the result vector with -1
    stack<int> st; // stack to keep track of the indices of the elements in the array
    for (int i = nums.size() - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] > nums[i]) {
            result[st.top()] = nums[i]; // the popped element will have the current element as its next smaller element
            st.pop(); // pop the indices of the elements that are greater than the current element
        }
        st.push(i);
    }
    return result;
}
```

### Monotonic Decreasing Stack

- A monotonic decreasing stack is a stack that maintains its elements in decreasing order.
- This means that the top of the stack will always be the largest element in the stack.
- When we push a new element onto the stack, we will pop all the elements from the stack that are smaller than the new element until we find an element that is greater than or equal to the new element. This way, we maintain the decreasing order of the elements in the stack.

```cpp
// Example of a monotonic decreasing stack
// We will use a stack to keep track of the indices of the elements in the array.
// We will iterate through the array and for each element, we will pop the elements from the stack until we find an element that is greater than or equal to the current element.
stack<int> st; // stack to keep track of the indices of the elements in the array
for (int i = 0; i < nums.size(); i++) {
    while (!st.empty() && nums[st.top()] < nums[i]) {
        st.pop(); // pop the indices of the elements that are smaller than the current element
    }
    st.push(i);
}
```

#### Next Greater Element (Left)

- Brute Force: O(n^2) -> For each element, we will iterate through the array to find the next greater element.
- Monotonic Stack: O(n) -> We will use a monotonic decreasing stack to find the next greater element for each element in the array. We will iterate through the array and for each element, we will pop the elements from the stack until we find an element that is greater than or equal to the current element. The popped elements will have the current element as their next greater element.

```cpp
vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> result(nums.size(), -1); // initialize the result vector with -1
    stack<int> st; // stack to keep track of the indices of the elements in the array
    for (int i = 0; i < nums.size(); i++) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            result[st.top()] = nums[i]; // the popped element will have the current element as its next greater element
            st.pop(); // pop the indices of the elements that are smaller than the current element
        }
        st.push(i);
    }
    return result;
}
```

#### Next Greater Element (Right)

- Just iterate from the end of the array and do the same as above. The popped elements will have the current element as their next greater element.

```cpp
vector<int> nextGreaterElementRight(vector<int>& nums) {
    vector<int> result(nums.size(), -1); // initialize the result vector with -1
    stack<int> st; // stack to keep track of the indices of the elements in the array
    for (int i = nums.size() - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            result[st.top()] = nums[i]; // the popped element will have the current element as its next greater element
            st.pop(); // pop the indices of the elements that are smaller than the current element
        }
        st.push(i);
    }
    return result;
}
```

## Monotonic Queue

- A monotonic queue is a queue that maintains its elements in a specific order, either increasing or decreasing.
- We can use a monotonic queue to solve problems like **sliding window maximum/minimum**, **finding min/max in dynamic ranges**, **stock span problems**, etc. The idea is similar to the monotonic stack, but instead of using a stack, we will use a queue to maintain the order of the elements.
- Often implemented using a deque (double-ended queue) to allow for efficient insertion and deletion from both ends of the queue.

### Monotonic Increasing Queue

- A monotonic increasing queue is a queue that maintains its elements in increasing order.
- This means that the front of the queue will always be the smallest element in the queue.
- When we add a new element to the queue, we will remove all the elements from the back of the queue that are greater than the new element until we find an element that is smaller than or equal to the new element. This way, we maintain the increasing order of the elements in the queue.

```cpp
// Example of a monotonic increasing queue

deque<int> dq; // deque to keep track of the indices of the elements in the array
for (int i = 0; i < nums.size(); i++) {
    while (!dq.empty() && nums[dq.back()] > nums[i]) {
        dq.pop_back(); // remove the indices of the elements that are greater than the current element
    }
    dq.push_back(i);
}
```

#### Sliding Window Minimum

- Brute Force: O(n\*k) -> For each element, we will iterate through the next k elements to find the minimum element in the sliding window.
- Monotonic Queue: O(n) -> We will use a monotonic increasing queue to find the minimum element in the sliding window.

```cpp
vector<int> minSlidingWindow(vector<int>& nums, int k) {
    vector<int> result; // vector to store the minimum elements in the sliding window
    deque<int> dq; // deque to keep track of the indices of the elements in the array
    for (int i = 0; i < nums.size(); i++) {
        while (!dq.empty() && nums[dq.back()] > nums[i]) {
            dq.pop_back(); // remove the indices of the elements that are greater than the current element
        }
        dq.push_back(i);
        if (i >= k - 1) { // we have formed a valid window
            result.push_back(nums[dq.front()]); // the front of the deque will be the index of the minimum element in the current window
            if (dq.front() == i - k + 1) { // remove the indices of the elements that are out of the current window
                dq.pop_front();
            }
        }
    }
    return result;
}
```

### Monotonic Decreasing Queue

- Just like the monotonic increasing queue, we can implement a monotonic decreasing queue to find the maximum element in the sliding window.

```cpp
// Example of a monotonic decreasing queue

deque<int> dq; // deque to keep track of the indices of the elements in the array
for (int i = 0; i < nums.size(); i++) {
    while (!dq.empty() && nums[dq.back()] < nums[i]) {
        dq.pop_back(); // remove the indices of the elements that are smaller than the current element
    }
    dq.push_back(i);
}
```

#### Sliding Window Maximum

- Brute Force: O(n\*k) -> For each element, we will iterate through the next k elements to find the maximum element in the sliding window.
- Monotonic Queue: O(n) -> We will use a monotonic decreasing queue to find the maximum element in the sliding window.

```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result; // vector to store the maximum elements in the sliding window
    deque<int> dq; // deque to keep track of the indices of the elements in the array
    for (int i = 0; i < nums.size(); i++) {
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back(); // remove the indices of the elements that are smaller than the current element
        }
        dq.push_back(i);
        if (i >= k - 1) { // we have formed a valid window
            result.push_back(nums[dq.front()]); // the front of the deque will be the index of the maximum element in the current window
            if (dq.front() == i - k + 1) { // remove the indices of the elements that are out of the current window
                dq.pop_front();
            }
        }
    }
    return result;
}
```
