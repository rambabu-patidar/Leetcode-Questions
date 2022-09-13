#include<bits/stdc++.h>
using namespace std;

// Q. https://leetcode.com/problems/median-of-two-sorted-arrays/

// effiecient solution : https://www.youtube.com/watch?v=q6IEA26hvXc

// Brute force approach
class Solution{
    public: 
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // first create an array of double the size

        vector<int> v(nums1.size() + nums2.size());

        int i = 0;
        int j = 0;
        int k = 0;

        while (i != nums1.size() && j != nums2.size()) {
            if (nums1[i] < nums2[j])  {
                v[k] = nums1[i];
                k++; i++;
            } else {
                v[k++] = nums2[j++];
            }
        }

        while (i != nums1.size()) {
            v[k++] = nums1[i++];
        }
        while (j != nums2.size()) {
            v[k++] = nums2[j++];
        }

        if ((v.size() & 1) == 1 ) {
            return (double)(v[v.size()/ 2]);
        } else {
            double ans = (double)(v[v.size() / 2] + v[(v.size() / 2) - 1]) / (double)(2);
            return ans;
        }
    }
};

int main() {

    return 0;
}