package com.LeetcodeQuestions.BinaryTree;

public class SameTree {
    TreeNode root;

    public SameTree() {
    }

//    Q. https://leetcode.com/problems/same-tree/

    public boolean isSameTree(TreeNode p, TreeNode q) {
        // if the both root are null
        if (p == null && q == null ) {
            return true;
        }
        // if none of them is null and val are also equal return true;
        if (p != null && q != null) {
            if (p.val == q.val) {
                return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
            }
        }
//        otherwise false
        return false;
    }

    static class TreeNode{
        private int val;
        public TreeNode left;
        public TreeNode right;

        public TreeNode() {
        }

        public TreeNode(int val) {
            this.val = val;
        }

        public TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    // if you want to check answers by custom solution make your own
    // tree otherwise what I recommend is to check be submitting directly on leetcode.
    // you can check custom testcases their also.

}
