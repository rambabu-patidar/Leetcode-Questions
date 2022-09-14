#include<bits/stdc++.h>
using namespace std;

// Q. https://leetcode.com/problems/min-stack/
class MinStack {
public:
    stack<int> st;
        stack<int> minSt;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()){
            minSt.push(val);
        }
    }
    
    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main () {

    return 0;
}