#include<bits/stdc++.h>
using namespace std;

class ListNode;

// code here

class Solution {
public:

    // Q. https://leetcode.com/problems/reorder-list/

    ListNode* getMid(ListNode* head) {
        // return second node in case of even number of node
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* next = head->next;
        ListNode* node = head;

        while (node != NULL) {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {

        // if we have 0 1 or 2 nodes nothing to do.
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return;
        }

        ListNode* mid = reverse(getMid(head));
        ListNode* midHead =  mid;
        ListNode* node = head;
        while (midHead != NULL && node != NULL ) {
            ListNode* temp = node->next;
            node->next = midHead;
            node = temp;
            temp = midHead->next;
            midHead->next = node;
            midHead = temp;
        }

    }
};

// ___________________________________________________________________
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
