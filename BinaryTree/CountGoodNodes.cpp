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
    return 0;
}