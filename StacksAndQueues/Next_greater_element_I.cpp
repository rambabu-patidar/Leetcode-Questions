#include<bits/stdc++.h>
using namespace std;

// Q. https://leetcode.com/problems/next-greater-element-i/

// Brute force approach

class Solution1 {
public:
    
    int binarySearch(vector<int> arr, int value) {
         for(int i = 0; i<arr.size(); i++) {
            if (arr[i] == value) {
                return i;
            }
        }

        return -1;
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        
        for(int i = 0; i < nums1.size(); i++) {
            int index = binarySearch(nums2, nums1[i]);
            int j;
            for( j = index + 1; j < nums2.size(); j++) {
                if (nums2[j] > nums1[i] ){
                    ans.push_back(nums2[j]);
                    break;
                } 
            }
            
            if (j == nums2.size()) {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};


// efficeint approach using only stack
// this can still be modified to a better solution using maping.

class Solution{
    public:
        int linearSearch(vector<int> v, int value)
        {
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] == value)
                {
                    return i;
                }
            }

            return -1;
        }

        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            stack<int> st;
            // this is next greater element of all the element.
            vector<int> nge(nums2.size());

            for (int i = nums2.size() - 1; i>=0; i--) {
                if (i == nums2.size() - 1) {
                    nge[i] = -1;
                    st.push(nums2[i]);
                } else {
                    if (nums2[i] > st.top()) {
                        while(!st.empty() && !(nums2[i] < st.top())) {
                            st.pop();
                        }
                        if(!st.empty()) {
                            nge[i] = st.top();
                        } else {
                            nge[i] = -1;
                        }
                        
                    } else {
                        nge[i] = st.top();
                    }

                    st.push(nums2[i]);
                }
            }
            vector<int> ans;
            for(int i = 0; i < nums1.size(); i++) {
                int index = linearSearch(nums2, nums1[i]);
                ans.push_back(nge[index]);
            }
            return ans;
        }
};

int main() {
    vector<int> arr = {5, 2, 3};
    vector<int>  arr2 ={1, 5, 7, 2, 3, 9, 8, 10};

    Solution s;
    vector<int > ans = s.nextGreaterElement(arr, arr2);
    for(int num : ans ) {
        cout << num << " ";
    }
    return 0;
}