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

int count = 0;
int goodNodes(TreeNode* root, int max) {
    if ( root == nullptr) {
            return 0;
    }

    if (root->val >= max) {
        max = root->val;
    }
    
    if (root->val >= max) {
       count+= 1;
    }
    else {
         return goodNodes(root->left, max) + goodNodes(root->right, max);
    }
    
   
        
}

int main () {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    cout << goodNodes(root, root->val);
    return 0;
}