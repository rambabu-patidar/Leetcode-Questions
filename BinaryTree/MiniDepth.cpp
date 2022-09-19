class TreeNode;

class Solution {
public:
    
    int minDepth(TreeNode* root) {
        //level order traversal 
        if (root == NULL) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        
        while (!q.empty()) {
            int n = q.size();
            level += 1;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                bool flag = false;
                if (node->left != NULL) {
                    flag = true;
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    flag = true;
                    q.push(node->right);
                }
                if (!flag) {
                    return level;
                }
            }
                 
        }
        return 0;
    }
//     int minDepth(TreeNode* root) {
//         if (root == NULL) {
//             return 0;
//         }
        
//         if (root->left == NULL && root->right == NULL) {
//             return 1;
//         }
//         if (root->left != NULL && root->right != NULL) {
//             return min(minDepth(root->left), minDepth(root->right)) + 1;
//         }else {
//             if(root->left != NULL) {
//                 return min(minDepth(root->left), 100001) + 1;
//             }else {
//                 return min(minDepth(root->right), 100001) + 1;
//             }
//         }
//     }
};


class TreeNode{
	public:
		int val;
		TreeNode* left;
		TreeNode* right;

		TreeNode(){}
		TreeNode(int val): val(val){
		this->left = NULL;
		this->right = NULL;
		}
		TreeNode(int val, TreeNode*left, TreeNode* right): val(val){
			this->left = left;
			this->right = right;
		}
}
