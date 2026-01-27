#include <bits/stdc++.h>
using namespace std;

bool palindromeCheck(string& s) {

    return isPalindrome(s, 0, s.size() - 1);
}

bool isPalindrome(string& s, int left, int right) {
    if(left >= right) return true;

    if(s[left] != s[right]) return false;

    return isPalindrome(s, left + 1, right - 1);
}

int main()
{
    vector<string> vals = {"oppo", "", ""};
    for(auto it : vals) {
        cout << palindromeCheck << " ";
    }
    cout << endl;
    
    return 0;
}