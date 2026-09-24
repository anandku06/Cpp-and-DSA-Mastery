// 901. Online Stock Span
// Medium
// Topics
// premium lock icon
// Companies
// Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

// The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

// For example, if the prices of the stock in the last four days are [7,2,1,2] and the price of the stock today is 2, then the span of today is 3 because starting from today, the price of the stock was less than or equal to 2 for 3 consecutive days.
// Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
// Implement the StockSpanner class:

// StockSpanner() Initializes the object of the class.
// int next(int price) Returns the span of the stock's price given that today's price is price.

// Example 1:

// Input
// ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
// [[], [100], [80], [60], [70], [60], [75], [85]]
// Output
// [null, 1, 1, 1, 2, 1, 4, 6]

// Explanation
// StockSpanner stockSpanner = new StockSpanner();
// stockSpanner.next(100); // return 1
// stockSpanner.next(80);  // return 1
// stockSpanner.next(60);  // return 1
// stockSpanner.next(70);  // return 2
// stockSpanner.next(60);  // return 1
// stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
// stockSpanner.next(85);  // return 6

// Constraints:

// 1 <= price <= 105
// At most 104 calls will be made to next.

// approach 1 -> brute force approach -> O(n^2) -> for each price, we will check the previous prices and count the number of prices which are less than or equal to the current price
// approach 2 -> using stack -> O(n) -> we will use a stack to store the prices and their respective spans, for each price, we will pop the prices from the stack which are less than or equal to the current price and add their spans to the current span, then we will push the current price and its span to the stack

#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
    StockSpanner()
    {
    }
    stack<pair<int, int>> st; // stack to store the price and its span
    int next(int price)
    {
        int span = 1;                                  // span of the current price
        while (!st.empty() && st.top().first <= price) // if the top of the stack is less than or equal to the current price, we will pop it and add its span to the current span
        {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span}); // push the current price and its span to the stack
        return span;            // return the span of the current price
    }
};