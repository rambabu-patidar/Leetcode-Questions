#include<bits/stdc++.h>
using namespace std;

class TreeNode;


// Q. https://leetcode.com/problems/path-sum/

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, targetSum, 0);
    }
    
    bool helper(TreeNode* root, int targetSum, int sum) {
        if (root == NULL) {
            return false;
        }
        sum += root->val; // In first time forgot to see that if the path is ending with leaf node or not.
        if (sum == targetSum && root->left == NULL && root->right == NULL) {
            return true;
        }
        
        bool left = helper(root->left, targetSum, sum);
        bool right = helper(root->right , targetSum, sum);
        
        return left || right;
        
    }
};

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode() {

        }
        TreeNode(int val): val(val) {};

        TreeNode(int val, TreeNode* left, TreeNode* right) : val(val) {
            this->left = left;
            this->right = right;
        }
};

int main(){

    
    return 0;
}