#include<bits/stdc++.h>
using namespace std;

// Q. https://leetcode.com/problems/product-of-array-except-self/

// more effiecient solution : https://leetcode.com/problems/product-of-array-except-self/discuss/2551206/C%2B%2B-Simple-Solution-oror-Single-Pass

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // one array will contain previous product
        int prevProd[nums.size()];
        int product = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 ) {
                prevProd[i] = 1;
            } else {
                product = product * nums[i - 1];
                prevProd[i] = product;
            }
        }

        // one array will contain next product to all the numbers.
        int nextProd[nums.size()];
        product =  1;
        for(int i = nums.size() - 1; i>=0; i--) {
            if( i == nums.size() - 1 ) {
                nextProd[i] = 1;
            } else {
               product = product * nums[i + 1];
                nextProd[i] = product;
            }
        }

        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size() - 1; i++) {
            ans[i] = prevProd[i] * nextProd[i];
        }
        return ans;
    }
};