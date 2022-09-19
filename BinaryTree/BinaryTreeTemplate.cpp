#include<iostream>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0){
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(int val) : val(val){
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(int val, TreeNode* left, TreeNode* right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
    
};


int main () {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);


    return 0;
}