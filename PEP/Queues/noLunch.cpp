// 1700. Number of Students unable to eat Lunch

// The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.

// The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:

// If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
// Otherwise, they will leave it and go to the queue's end.
// This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

// You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). Return the number of students that are unable to eat.

// Example 1:

// Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
// Output: 0
// Explanation:
// - Front student leaves the top sandwich and returns to the end of the line making students = [1,0,0,1].
// - Front student leaves the top sandwich and returns to the end of the line making students = [0,0,1,1].
// - Front student takes the top sandwich and leaves the line making students = [0,1,1] and sandwiches = [1,0,1].
// - Front student leaves the top sandwich and returns to the end of the line making students = [1,1,0].
// - Front student takes the top sandwich and leaves the line making students = [1,0] and sandwiches = [0,1].
// - Front student leaves the top sandwich and returns to the end of the line making students = [0,1].
// - Front student takes the top sandwich and leaves the line making students = [1] and sandwiches = [1].
// - Front student takes the top sandwich and leaves the line making students = [] and sandwiches = [].
// Hence all students are able to eat.
// Example 2:

// Input: students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
// Output: 3

// Constraints:

// 1 <= students.length, sandwiches.length <= 100
// students.length == sandwiches.length
// sandwiches[i] is 0 or 1.
// students[i] is 0 or 1.

// approach: The problem can be solved by simulating the process of students taking sandwiches. We can use a queue to represent the students and a stack to represent the sandwiches. We can iterate through the students and for each student, we can check if they prefer the sandwich on the top of the stack. If they do, we remove them from the queue and pop the sandwich from the stack. If they don't, we move them to the end of the queue. We continue this process until none of the students want to take the top sandwich. Finally, we return the number of students remaining in the queue.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int n = students.size();

        queue<int> studQueue;
        stack<int> sandStack;

        for (int i = 0; i < n; i++)
        {
            studQueue.push(students[i]);
            sandStack.push(sandwiches[n - i - 1]); // push the sandwiches in reverse order to simulate the stack
        }

        int lastServed = 0;
        while (!studQueue.empty() && lastServed < studQueue.size())
        {
            if (sandStack.top() == studQueue.front())
            {
                sandStack.pop();
                studQueue.pop();
                lastServed = 0;
            }
            else
            {
                studQueue.push(studQueue.front());
                studQueue.pop();
                lastServed++;
            }
        }

        return studQueue.size();
    }
};