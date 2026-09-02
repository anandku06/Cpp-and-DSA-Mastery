#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decimalToBinary(int n)
    {
        string res = "";

        while (n > 0)
        {
            if (n % 2 == 1)
                res += "1";
            else
                res += "0";

            n /= 2;
        }

        reverse(res);

        return res;
    }

    int binaryToDecimal(string s)
    {
        int base = 1;
        int num = 0;
        int len = s.size();

        for (int i = len - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                num += base;
            }

            base *= 2;
        }

        return num;
    }

    // Function to swap two numbers using bitwise XOR operation
    // approach: a = a ^ b, b = a ^ b, a = a ^ b
    // why it works:
    // 1. After the first operation, a becomes a ^ b.
    // 2. After the second operation, b becomes (a ^ b) ^ b = a.
    // 3. After the third operation, a becomes (a ^ b) ^ a = b.
    void swapTwoNumbers(int &a, int &b)
    {
        a = a ^ b; // Step 1: a becomes a ^ b
        b = a ^ b; // Step 2: b becomes (a ^ b) ^ b = a
        a = a ^ b; // Step 3: a becomes (a ^ b) ^ a = b
    }

    // Function to check if the ith bit of a number is set (1) or not (0)
    // approach: use bitwise AND operation with a mask (1 << i)
    // why it works: if the ith bit is set, the result of the AND operation will be non-zero; otherwise, it will be zero.
    // example: n = 5 (binary: 101), i = 2, mask = 1 << 2 = 100, n & mask = 101 & 100 = 100 (non-zero, so the 2nd bit is set)
    bool checkIfIthBitIsSet(int n, int i)
    {
        return (n & (1 << i)) != 0; // check if the ith bit is set by performing a bitwise AND operation with a mask

        return (n >> i) & 1; // alternative approach: right shift n by i positions and check if the least significant bit is 1
    }

    // Function to set the ith bit of a number to 1
    // approach: use bitwise OR operation with a mask (1 << i)
    // why it works: the OR operation will set the ith bit to 1 regardless of its previous value.
    // example: n = 5 (binary: 101), i = 1, mask = 1 << 1 = 010, n | mask = 101 | 010 = 111 (the 1st bit is set to 1)
    int setIthBit(int n, int i)
    {
        return n | (1 << i); // set the ith bit to 1 by performing a bitwise OR operation with a mask
    }

    // Function to clear the ith bit of a number (set it to 0)
    // approach: use bitwise AND operation with the negation of a mask (~(1 << i))
    // why it works: the AND operation will clear the ith bit to 0 regardless of its previous value.
    // example: n = 5 (binary: 101), i = 0, mask = 1 << 0 = 001, ~mask = 110, n & ~mask = 101 & 110 = 100 (the 0th bit is cleared to 0)
    int clearIthBit(int n, int i)
    {
        return n & ~(1 << i); // clear the ith bit to 0 by performing a bitwise AND operation with the negation of a mask
    }

    // Function to toggle the ith bit of a number (flip it)
    // approach: use bitwise XOR operation with a mask (1 << i)
    // why it works: the XOR operation will flip the ith bit regardless of its previous value.
    // example: n = 5 (binary: 101), i = 1, mask = 1 << 1 = 010, n ^ mask = 101 ^ 010 = 111 (the 1st bit is toggled from 0 to 1)
    int toggleIthBit(int n, int i)
    {
        return n ^ (1 << i); // toggle the ith bit by performing a bitwise XOR operation with a mask
    }

    // function to check if a number has all set bits (1s) in its binary representation
    // approach: use the property that a number with all set bits is of the form 2^k - 1, where k is the number of bits. Therefore, n & (n + 1) should be 0 for such numbers.
    // why it works: if n has all set bits, then n + 1 will be a power of 2, and the AND operation will yield 0.
    // example: n = 7 (binary: 111), n + 1 = 8 (binary: 1000), n & (n + 1) = 111 & 1000 = 000 (all set bits)
    bool hasAllSetBits(int n)
    {
        return (n & (n + 1)) == 0; // check if n has all set bits by performing a bitwise AND operation with (n + 1)
    }

    // function to remove the last set bit of a number
    // approach: use bitwise AND operation with (n - 1)
    // why it works: subtracting 1 from n flips all the bits after the last set bit (including the last set bit itself).
    // example: n = 12 (binary: 1100), n - 1 = 11 (binary: 1011), n & (n - 1) = 1100 & 1011 = 1000 (the last set bit is removed)
    int removeLastSetBit(int n)
    {
        return n & (n - 1); // remove the last set bit by performing a bitwise AND operation with (n - 1)
    }

    // vice versa, we can set the last unset bit of a number by performing a bitwise OR operation with (n + 1)
    int setLastSetBit(int n)
    {
        return n | (n + 1); // set the last unset bit by performing a bitwise OR operation with (n + 1)
    }

    // function to check if a number is a power of 2
    // approach: use the property that a power of 2 has exactly one set bit in its binary representation. Therefore, n & (n - 1) should be 0 for such numbers.
    // why it works: if n is a power of 2, then n - 1 will have all bits set to the right of the single set bit in n, and the AND operation will yield 0.
    // example: n = 8 (binary: 1000), n - 1 = 7 (binary: 0111), n & (n - 1) = 1000 & 0111 = 0000 (power of 2)
    bool isPowerOfTwo(int n)
    {
        return (n > 0) && ((n & (n - 1)) == 0); // check if n is a power of 2 by performing a bitwise AND operation with (n - 1)
    }

    // function to count the number of set bits (1s) in the binary representation of a number
    // approach: use Brian Kernighan's algorithm, which repeatedly removes the last set bit from the number until it becomes 0.
    // why it works: each time we perform n = n & (n - 1), we remove the last set bit from n, and we can count how many times we do this until n becomes 0.
    // example: n = 13 (binary: 1101), n & (n - 1) = 1101 & 1100 = 1100 (count = 1), n & (n - 1) = 1100 & 1011 = 1000 (count = 2), n & (n - 1) = 1000 & 0111 = 0000 (count = 3)
    int countSetBits(int n)
    {
        int count = 0;

        while (n > 0)
        {
            n = n & (n - 1); // remove the last set bit from n
            count++;         // increment the count of set bits
        }

        return count; // return the total count of set bits
    }
};

// function to get the rightmost set bit of a number
// approach: use bitwise AND operation with the negative of the number
// why it works: the negative of a number in two's complement representation flips all the bits and adds 1, so the AND operation will isolate the rightmost set bit.
// example: n = 12 (binary: 1100), -n = -12 (binary: 0100), n & (-n) = 1100 & 0100 = 0100 (the rightmost set bit)
int getRightmostSetBit(int n)
{
    return n & (-n); // return the rightmost set bit by performing a bitwise AND operation with the negative of n
}