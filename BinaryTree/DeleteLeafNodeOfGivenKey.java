package com.LeetcodeQuestions.BinaryTree;

// use OOPS concept also so that they are also revisited.

public class DeleteLeafNodeOfGivenKey extends BinaryTreeTemplate{

//    Q. https://leetcode.com/problems/delete-leaves-with-a-given-value/

    public TreeNode removeLeafNodes(TreeNode root, int target) {
        if (root == null) {
            return null;
        }

        root.left = removeLeafNodes(root.left, target);
        root.right = removeLeafNodes(root.right, target);

        if (root.left == null && root.right == null && root.val == target) {
            return null;
        }
        return root;
    }

    public static void main(String[] args) {
        DeleteLeafNodeOfGivenKey tree = new DeleteLeafNodeOfGivenKey();
        tree.root = new TreeNode(1);
        tree.root.left = new TreeNode(2);
    }
}
