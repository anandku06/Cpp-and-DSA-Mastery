#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char fRod, char tRod, char auxRod)
{
    if(n == 1) cout << "Move disk 1 to rod " << fRod << " to rod " << tRod << endl;

    towerOfHanoi(n - 1, fRod, auxRod, tRod);
    cout << "Move disc " << n << " from rod " << fRod << " to rod " << tRod << endl;
    towerOfHanoi(n - 1, auxRod, tRod, fRod);
}

int main()
{
    int n;
    cin >> n;

    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}