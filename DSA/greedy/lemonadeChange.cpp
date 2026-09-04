// 860. Lemonade Change
// Easy
// Topics
// premium lock icon
// Companies
// At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

// Note that you do not have any change in hand at first.

// Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.

// Example 1:

// Input: bills = [5,5,5,10,20]
// Output: true
// Explanation:
// From the first 3 customers, we collect three $5 bills in order.
// From the fourth customer, we collect a $10 bill and give back a $5.
// From the fifth customer, we give a $10 bill and a $5 bill.
// Since all customers got correct change, we output true.
// Example 2:

// Input: bills = [5,5,10,10,20]
// Output: false
// Explanation:
// From the first two customers in order, we collect two $5 bills.
// For the next two customers in order, we collect a $10 bill and give back a $5 bill.
// For the last customer, we can not give the change of $15 back because we only have two $10 bills.
// Since not every customer received the correct change, the answer is false.

// Constraints:

// 1 <= bills.length <= 105
// bills[i] is either 5, 10, or 20.

// approach: The problem can be solved using a greedy algorithm. We can keep track of the number of $5 and $10 bills we have in hand. For each customer, we check the bill they pay with and provide the correct change accordingly. If we cannot provide the correct change for any customer, we return false. If we can provide change for all customers, we return true.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0; // number of $5 bills in hand
        int ten = 0;  // number of $10 bills in hand

        for (int bill : bills) // iterate through the bills array
        {
            if (bill == 5) // if the customer pays with a $5 bill
            {
                five++; // increment the count of $5 bills
            }
            else if (bill == 10) // if the customer pays with a $10 bill
            {
                if (five == 0) // if we don't have any $5 bills to give change
                {
                    return false; // we cannot provide change, return false
                }
                five--; // give one $5 bill as change
                ten++;  // increment the count of $10 bills
            }
            else if (bill == 20) // if the customer pays with a $20 bill
            {
                if (ten > 0 && five > 0) // if we have both $10 and $5 bills to give change
                {
                    ten--;  // give one $10 bill as change
                    five--; // give one $5 bill as change
                }
                else if (five >= 3) // if we have at least three $5 bills to give change
                {
                    five -= 3; // give three $5 bills as change
                }
                else // if we cannot provide change for the $20 bill
                {
                    return false; // return false
                }
            }
        }

        return true; // we were able to provide change for all customers, return true
    }
};