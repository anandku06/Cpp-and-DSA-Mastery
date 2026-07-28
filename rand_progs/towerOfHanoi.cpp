// Tower Of Hanoi
// Solved
// Difficulty: MediumAccuracy: 35.23%Submissions: 210K+Points: 4
// You are given n disks placed on a starting rod (from), with the smallest disk on top and the largest at the bottom. There are three rods: the starting rod(from), the target rod (to), and an auxiliary rod (aux).
// You have to calculate the minimum number of moves required to transfer all n disks from the starting rod to the target rod, following these rules:
//       1. Only one disk can be moved at a time.
//       2. A disk can only be placed on top of a larger disk or on an empty rod.
// Return the minimum number of moves needed to complete the task.

// Examples:

// Input: n = 2
// Output: 3
// Explanation: For n = 2, total 3 steps will be taken. Steps are as follows -
// move disk 1 from rod 1 to rod 2
// move disk 2 from rod 1 to rod 3
// move disk 1 from rod 2 to rod 3
// Input: n = 3
// Output: 7
// Explanation: For n = 3, total 7 steps will be taken.Steps are as follows -
// move disk 1 from rod 1 to rod 3
// move disk 2 from rod 1 to rod 2
// move disk 1 from rod 3 to rod 2
// move disk 3 from rod 1 to rod 3
// move disk 1 from rod 2 to rod 1
// move disk 2 from rod 2 to rod 3
// move disk 1 from rod 1 to rod 3
// Input: n = 0
// Output: 0
// Explanation: Total 0 steps will be taken.
// Constraints:
//   0 ≤ n ≤ 20

// Approach: The Tower of Hanoi problem can be solved using recursion. The idea is to move n-1 disks from the source rod to the auxiliary rod, then move the nth disk from the source rod to the target rod, and finally move the n-1 disks from the auxiliary rod to the target rod. This process is repeated recursively until all disks are moved to the target rod.

#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char fRod, char tRod, char auxRod)
{
    if (n == 1)
        cout << "Move disk 1 to rod " << fRod << " to rod " << tRod << endl;

    towerOfHanoi(n - 1, fRod, auxRod, tRod);
    cout << "Move disc " << n << " from rod " << fRod << " to rod " << tRod << endl;
    towerOfHanoi(n - 1, auxRod, tRod, fRod);
}

// Function to calculate the minimum number of moves required to transfer n disks from the starting rod to the target rod, following the rules of the Tower of Hanoi problem. The minimum number of moves required is given by the formula 2^n - 1, where n is the number of disks. This function uses recursion to calculate the minimum number of moves.
int towerOfHanoiMoves(int n)
{
    if (n == 0)
        return 0;
    return (1 << n) - 1; // Minimum moves required is 2^n - 1
}

int main()
{
    int n;
    cin >> n;

    towerOfHanoi(n, 'A', 'C', 'B');
    cout << "Minimum moves required: " << towerOfHanoiMoves(n) << endl;
    return 0;
}