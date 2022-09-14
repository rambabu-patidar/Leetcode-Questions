#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

class ListNode;

// Q. https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

class Solution {
public:
    int pairSum(ListNode* head) {
        // reverse the half list and find solution and again make the list as it is by 
        // reversing the half again.
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        while (fast != NULL) {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev->next = reverse(slow);
        prev = prev->next; // this will be on the middle node
        slow = head;
        int maximum = -1;
        while (prev != NULL) {
            maximum = max(maximum, prev->val + slow->val);
            fast = slow; // as this is now free so we can use it to point to prev of slow we can creat new but it will take space.
            prev = prev->next;
            slow = slow->next;
        }

        fast->next = reverse(slow);
        return maximum;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* node = head;
        ListNode* next = node->next;

        while (node != NULL) {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
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

