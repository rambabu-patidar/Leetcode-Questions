#include<bits/stdc++.h>
using namespace std;

// Q. https://leetcode.com/problems/remove-linked-list-elements/submissions/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


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


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        
        while (head != nullptr && head->val == val) {
            head = head->next;
        }
        
        if (head == nullptr) {
            return head;
        }
        
        ListNode* node = head;
        
        while (node->next != nullptr) {
            if (node->next->val == val) {
                node->next = node->next->next;
            }
            else {
                node = node->next;
            }
        }
        
        return head;
        
    }
};