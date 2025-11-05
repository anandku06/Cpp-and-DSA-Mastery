class Solution {
public:
    bool isPalindrome(int n) {
        int temp = n;
        int revNum = 0;
        while(temp > 0)
        {
            int rem = temp % 10;
            revNum = (revNum * 10) + rem;
            temp /= 10;
        }

        if(revNum == n) return true;
        else return false;
    }
};