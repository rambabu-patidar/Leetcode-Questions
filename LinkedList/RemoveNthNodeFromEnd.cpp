#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode()
    {
    }

    ListNode(int val) : next(nullptr)
    {
        this->val = val;
    }

    ListNode(int val, ListNode *next) : val(val), next(next)
    {
    }
};

int size(ListNode *head)
{
    int count = 0;
    ListNode *node = head;
    while (node != NULL)
    {
        node = node->next;
        count += 1;
    }

    return count;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int length = size(head);
    ListNode *node = head;
    int k = (length - n);

    if (k == 0)
    {
        return head->next;
    }
    while (k != 1)
    {
        node = node->next;
        k--;
    }

    node->next = node->next->next;

    return head;
}