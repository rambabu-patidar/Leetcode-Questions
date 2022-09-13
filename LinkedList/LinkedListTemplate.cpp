#include<bits/stdc++.h>
using namespace std;

class ListNode;
// declaration so that the compiler know and
//we can use it before it is defined

// Code here



class ListNode {
    public:

    int val;
    ListNode* next;

    ListNode () {

    }

    ListNode(int val) : next(nullptr) {
        this->val = val;
    }

    ListNode(int val, ListNode* next ): val(val), next(next) {

    }
};
