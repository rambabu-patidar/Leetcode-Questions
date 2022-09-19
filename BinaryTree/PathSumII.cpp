#include<bits/stdc++.h>
using namespace std;

class TreeNode;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        return helper(root, targetSum,v , 0);
    }
    
    
    vector<vector<int>> helper(TreeNode* root, int targetSum, vector<int> v, int sum) {
        vector<vector<int>> list;
        if (root == NULL) {
            return list;
        }
        
        sum += root->val;
        v.push_back(root->val);
        
        if (sum == targetSum && root->left == NULL && root->right == NULL) {
            list.push_back(v);
            return list;
        }
        
        vector<vector<int>> left = helper(root->left, targetSum, v, sum);
        
        // v.pop_back();
        
        vector<vector<int>> right = helper(root->right, targetSum, v, sum);
        
        // v.pop_back();
        
        list.insert(list.end(), left.begin(), left.end());
        list.insert(list.end(), right.begin(), right.end());
        return list;
        
    }
};

class TreeNode {
    public:

      int val;
      TreeNode *left;
      TreeNode *right;
      // constructors
      
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };