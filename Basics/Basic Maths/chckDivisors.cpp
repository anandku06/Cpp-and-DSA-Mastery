#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> divisors(int n) {
        vector<int> div;
        // for(int i = 1; i <= n; i++)
        // {
        //     if(n % i == 0)
        //     div.push_back(i);
        // }
        for (int i = 1; i <= sqrt(n); i++)
        {
            if(n % i == 0)
            {
                div.push_back(i);
                if((n / i) != i)
                div.push_back((n / i));
            }
        }

        sort(div.begin(), div.end());

        return div;
    }
};


int main()
{
    Solution so;
    for(auto it : so.divisors(256))
    {
        cout << it << " ";
    }
    return 0;
}