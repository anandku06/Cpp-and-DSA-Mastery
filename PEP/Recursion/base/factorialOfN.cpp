#include <bits/stdc++.h>
using namespace std;

long long factorialUsingRecursion(int n) {
    if(n == 0 || n == 1) return 1;

    return n * factorialUsingRecursion(n - 1);
}

int main()
{
    cout << factorialUsingRecursion(5) << endl;
    return 0;
}