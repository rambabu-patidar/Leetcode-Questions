#include<bits/stdc++.h>
using namespace std;

// Q. https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    
    void moveZeroes(vector<int>& nums) {
        
        int ptr1 = 0;
        for(int ptr2 = 0; ptr2 < nums.size(); ptr2++) {
            if (nums[ptr2] == 0) {
                continue;
            } else {
                int temp = nums[ptr1];
                nums[ptr1] = nums[ptr2];
                nums[ptr2] = temp;
                ptr1++;
            }
        }
        
       
    }
};