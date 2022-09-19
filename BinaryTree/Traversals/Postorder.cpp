#include<bits/stdc++.h>
using namespace std;

class TreeNode;

class Solution{
    public:

    // Q. https://leetcode.com/problems/binary-tree-postorder-traversal/
    
        vector<int> postorderTraversal(TreeNode* root) {
            stack<TreeNode* > stack1;
            stack<TreeNode* > stack2; //  we can replace this with the vector directly
                                    // and then reverse the element to return

            stack1.push(root);

            while (!stack1.empty()) {
                TreeNode* node = stack1.top();
                stack2.push(stack1.top()); 
                stack1.pop();

                if (node->left != NULL) {
                    stack1.push(node->left);
                }
                if (node->right != NULL) {
                    stack1.push(node->right);
                }
            }
            vector<int> v; 
            while (!stack2.empty()) {
                v.push_back(stack2.top()->val);
                stack2.pop();
            }
            return v;
        }
};

class TreeNode : public Solution{
    public: 
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode() {
            // default constructor
        }

        TreeNode(int val ) {
            this->val =val;
            this->left = NULL;
            this->right = NULL;
        }
};