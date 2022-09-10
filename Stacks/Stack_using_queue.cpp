#include<bits/stdc++.h>
using namespace std;

// Q. https://leetcode.com/problems/implement-stack-using-queues/submissions/

class MyStack {
public:
    
    queue<int>* q1 = new queue<int>();
    queue<int>* q2 = new queue<int>();
    
    
    void push(int x) {
        q1->push(x);
        
        while( !q2->empty()) {
            q1->push(q2->front());
            q2->pop();
        }
        
        queue<int> *temp = q1;
        q1 = q2;
        q2 = temp;
    
    }
    
    int pop() {
        int value = q2->front();
        q2->pop();
        return value;
    }
    
    int top() {
        return q2->front();
    }
    
    bool empty() {
        return q2->empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {

    MyStack stack;
    stack.push(1);
    stack.push(3);
    stack.push(5);

    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    return 0;
}