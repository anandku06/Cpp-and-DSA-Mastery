class Solution {
public:
    int factorial(int n) {
        int fact = 1;

        if(n <= 1) return fact;

        for(int i = 2; i <= n; i++)
        {
            fact *= i;
        }

        return fact;
    }
};
