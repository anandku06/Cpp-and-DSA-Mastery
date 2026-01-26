// 238. Product of Array except Self

// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

// approach_1 : using nested loops and getting product of each elements just avoiding the current element
// appraoch_2 : using division, but have to handle some test_cases
// appraoch_3 : make two arrays for leftProduct and rightProduct, and then the result array will contain elements of leftProduct[i] * rightProduct[i]
// approach_4 : avoiding making seperate arrays for left and right product, just make resulArray as leftProduct and update the values with the rightProduct values stored in another var and updating that as well

// approach_4
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> approach_4(vector<int>& nums) {
            int n = nums.size();

            vector<int> result;
            result.push_back(1); // as for first element, the left prod is always be 1

            for(int i = 1; i < n; i++) {
                result.push_back(result[i - 1] * nums[i - 1]); // making it the prefix prod of the array
            }

            int rp = 1; // storing the right prod of each array element here

            for(int i = n - 1; i >= 0; i--) {
                result[i] *= rp; // product of each element's left and right product
                rp *= nums[i]; // updating the right prod for other elements
            }

            return result;
        }

        vector<int> approach_3(vector<int>& nums) {
            int n = nums.size();

            vector<int> result;

            vector<int> leftProd(n); // array for all left side products
            leftProd.push_back(1);

            vector<int> rightProd(n); // array for all right side prodcuts
            rightProd[n - 1] = 1;

            for(int i = 1; i < n; i++) {
                leftProd[i] = nums[i - 1] * leftProd[i - 1];
            }

            for(int i = n - 2; i >= 0; i--) {
                rightProd[i] = nums[i + 1] * rightProd[i + 1];
            }

            for (int i = 0; i < n; i++)
            {
                result[i] = leftProd[i] * rightProd[i];
            }
            
            return result;
        }
};