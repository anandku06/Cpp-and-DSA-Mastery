#include <bits/stdc++.h>
using namespace std;

void printToOneRec(int n) {
    if(n == 0) return;

    cout << n << " ";
    printToOneRec(n - 1);
}

int main()
{
    printToOneRec(10);
    return 0;
}