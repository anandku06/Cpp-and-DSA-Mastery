#include <bits/stdc++.h>
using namespace std;

void printToNRec(int n) {
    if(n == 0) return;

    printToNRec(n - 1);
    cout << n << " ";
}

int main()
{
    printToNRec(10);
    return 0;
}