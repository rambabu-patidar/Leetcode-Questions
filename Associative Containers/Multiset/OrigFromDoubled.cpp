#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Q. https://leetcode.com/problems/find-original-array-from-doubled-array/
    
    vector<int> findOriginalArray(vector<int>& changed) {

        if ((changed.size() & 1) == 1) {
            return {};
        }
        multiset<int> mset;

        for (int i = 0 ; i < changed.size(); i++) {
            mset.insert(changed[i]);
        }
        multiset<int> :: iterator it;
        vector<int> v;
        while (!mset.empty()) {
            int value = *mset.begin();
            mset.erase(mset.begin());
            if (mset.find(value * 2) == mset.end()) { 
                return {};
            }
            mset.erase(mset.find(value * 2));
            v.push_back(value);
        }
        return v;
    }
};
