#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

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

class ListNode;


class Solution {
public:
    int pairSum(ListNode* head) {
        // stack application. 
        stack<int> stack;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL) {
            stack.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        int maximum = -1;
        while (slow != NULL) {
            maximum = max(maximum, stack.top() + slow->val);
            slow = slow->next;
            stack.pop();
        }

        return maximum;
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

