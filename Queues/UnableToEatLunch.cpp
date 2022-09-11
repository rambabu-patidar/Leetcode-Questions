#include<bits/stdc++.h>
using namespace std;

// Q. https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for (int i = 0; i < students.size(); i++)
        {
            q.push(students[i]);
        }

        int ptr = 0;

        while (!q.empty()) {
            int size = 0;
            while (!q.empty() && q.front() == sandwiches[ptr]) {
                q.pop();
                ptr++;
            }
            while (!q.empty() && q.front() != sandwiches[ptr]) {
                size++;
                if (size > q.size()) {
                    return q.size();
                }
                q.push(q.front());
                q.pop();
            }
            
        }

        return 0;
    }
};

int main () {

    return 0;
}