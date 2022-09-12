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
    ListNode* deleteMiddle(ListNode* head) {
        // Don't require condition head == null because
        // The number of nodes in the list is in the range [1, 105]. Given.

        if (head->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // move slow pointer one time less than the fast because we 
        // want to reach to the node previous to the middle so that we can delete the 
        // middle node. Otherwise we have to keep the prev Pointer.

        while (fast != nullptr && fast->next != nullptr) {
            if (fast == slow) {
                fast = fast->next->next;
            } else {
                fast = fast->next->next;
                slow = slow->next;
            }
        }

        slow->next = slow->next->next;
        return head;
    }
};

int main() {
    return 0;
}