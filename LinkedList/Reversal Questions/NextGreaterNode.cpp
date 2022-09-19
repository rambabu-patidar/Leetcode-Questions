#include <bits/stdc++.h>
using namespace std;

class ListNode;

// code here

ListNode *reverse(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *next = head->next;
    ListNode *node = head;

    while (node != nullptr)
    {
        next = head->next;
        node->next = prev;
        prev = node;
        node = next;
    }
    return prev;
}
vector<int> nextLargerNodes(ListNode *head)
{
    // reverse the linked list

    head = reverse(head);

    stack<int> st;
    ListNode *node = head;

    vector<int> v;
    while (node != nullptr)
    {

        while (!st.empty() && node->val >= st.top())
        {
            st.pop();
        }

        if (st.empty() == true)
        {
            v.push_back(0);
        }
        else
        {
            v.push_back(st.top());
        }
        st.push(node->val);
        node = node->next;
    }

    
    return v;
}

// ___________________________________________________________________
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
