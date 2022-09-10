#include<bits/stdc++.h>
using namespace std;

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
class Solution {
public:

    stack<int> pushInStack(ListNode* node) {
        stack<int> st;
        while (node != NULL) {
            st.push(node->val);
            node = node->next;
        }
        return st;
    }

    stack<int> createFinalStack(stack<int> first, stack<int> second) {
        int carry = 0;
        stack<int> final;
        while (!first.empty() && !second.empty()) {
            int sum = first.top() + second.top() + carry;
            final.push(sum % 10);

            carry = (sum) / 10;
            first.pop();
            second.pop();
        }

        while (!first.empty()) {
            int sum = first.top()  + carry;
            final.push(sum % 10);

            carry = (sum) / 10;
            first.pop();
        }

        while (!second.empty()) {
            int sum = second.top()  + carry;
            final.push(sum % 10);

            carry = (sum) / 10;
            second.pop();
        }

        if (carry != 0) {
            final.push(carry);
        }
        return final;
    }

    ListNode* createLinkedList(stack<int> final) {
        ListNode* head = new ListNode(final.top());
        ListNode* node = head;
        final.pop();
        while (!final.empty()) {
            ListNode* newNode = new ListNode(final.top());
            node->next = newNode;
            node = node->next;
            final.pop();
        }
        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;
        stack<int> final;

        // put all the element of linked list 1 in stack 1
        st1 = pushInStack(l1);

        // put all the element of linked list 2 in stack 2
        st2 = pushInStack(l2);

        final = createFinalStack(st1, st2);

        return createLinkedList(final);
    }
};