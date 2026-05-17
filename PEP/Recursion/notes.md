# Recursion

- Recursion is a programming technique where a function calls itself in order to solve a problem. It typically involves a base case that stops the recursion and a recursive case that breaks the problem into smaller subproblems.

## Key Concepts of Recursion

1. Base Case: The condition under which the recursion will stop. It is essential to prevent infinite recursion and ensure that the function eventually returns a result.
2. Recursive Case: The part of the function that breaks the problem into smaller subproblems and calls itself to solve those subproblems.
3. Stack: Each time a function calls itself, a new frame is added to the call stack. When the base case is reached, the function starts returning values and unwinding the stack.

## Recursion Leap of Faith

- The "leap of faith" is a concept in recursion where the recursive function assumes that the recursive call will work correctly and returns the expected result. This allows the function to focus on solving the current problem without worrying about the correctness of the recursive calls.

### Example of Recursion Leap of Faith

```cpp
int sumOfNumbers(int n) {
    // Base case
    if (n == 0) {
        return 0;
    }
    // Recursive case: sum of numbers from 1 to n = n + sum of numbers from 1 to (n-1)
    return n + sumOfNumbers(n - 1);
}
```

In this example, the function `sumOfNumbers` assumes that the recursive call `sumOfNumbers(n - 1)` will return the correct sum of numbers from 1 to (n-1). This allows the function to focus on adding `n` to that result without worrying about how the recursive call is implemented.

## Recursion Tree

- A recursion tree is a visual representation of the recursive calls made by a function. It helps to understand the flow of the recursion and the relationships between the different calls. Each node in the tree represents a function call, and the edges represent the recursive calls made by that function.

## Recursion Call Stack

- The recursion call stack is a data structure that keeps track of the active function calls in a recursive program. Each time a function is called, a new frame is added to the stack, and when a function returns, its frame is removed from the stack. The call stack helps to manage the flow of the recursive calls and ensures that the program can return to the correct point after each call.

## Time Complexity of Recursion

- The time complexity of a recursive function can often be analyzed using the recursion tree or by solving the recurrence relation that describes the function. The time complexity depends on the number of recursive calls made and the work done in each call.
- For example, a recursive function that makes two recursive calls for each call and does O(1) work in each call would have a time complexity of O(2^n), while a function that makes one recursive call and does O(n) work in each call would have a time complexity of O(n^2).

## Space Complexity of Recursion

- The space complexity of a recursive function is determined by the maximum depth of the recursion and the amount of space used in each call. The space used in each call includes the local variables and the return address.
- For example, a recursive function that has a maximum depth of n and uses O(1) space in each call would have a space complexity of O(n), while a function that has a maximum depth of log(n) and uses O(1) space in each call would have a space complexity of O(log(n)).

## Tail Recursion

- Tail recursion is a special case of recursion where the recursive call is the last operation performed in the function. Tail recursion can be optimized by the compiler or interpreter into iterative code, which can reduce the overhead of function calls and improve performance.
- For example, a tail recursive function to calculate the factorial of a number can be implemented as follows:

```cpp
int factorial(int n, int accumulator = 1) {
    // Base case
    if (n == 0) {
        return accumulator;
    }
    // Tail recursive case: the recursive call is the last operation performed
    return factorial(n - 1, n * accumulator);
}
```