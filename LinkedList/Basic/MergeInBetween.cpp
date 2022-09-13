#include<bits/stdc++.h>
using namespace std;

class ListNode; // declaration to know that it is present below


class Solution {
public:

// Q. https://leetcode.com/problems/merge-in-between-linked-lists/
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* node = list1;

        for (int i = 0; i < a; i++) {
            node = node->next;
        }

        ListNode* temp = node;
        // move node ahead to the area which will be deleted
        node = node->next;
        // now make prev node to point to the head of list2
        temp->next = list2;

        int diff = b - a;

        while (diff != 0) {
            node = node->next;
            diff--;
        }

        // go at the end of the list2;
        temp = list2; // as the temp pointer work is done above we can ues it
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node->next;

        return list1;


    }
};

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
