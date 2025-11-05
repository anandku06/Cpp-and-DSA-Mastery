#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countDigit(int n)
    {
        int count = 0;
        while(n > 0)
        {
            int rem = n % 10;
            count++;
            n /= 10;
        }
        return count;
    }

    bool isArmstrong(int n) {
        int exp = countDigit(n);
        int temp = n;
        int sum = 0;

        while(temp > 0)
        {
            int rem = temp % 10;
            sum += pow(rem, exp);

            temp /= 10;
        }
        if(n == sum) return true;
        else return false;
    }
};


int main()
{
    Solution sol;
    cout << sol.isArmstrong(1634) << endl;
    return 0;
}