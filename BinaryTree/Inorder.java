package com.LeetcodeQuestions.BinaryTree;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

//Q. https://leetcode.com/problems/binary-tree-inorder-traversal/

public class Inorder {
    private TreeNode root;

    public Inorder() {
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        TreeNode node = root;
        List<Integer> list = new ArrayList<>();
        while (!stack.isEmpty() || node != null) {
            while (node != null) {
                stack.push(node);
                node = node.left;
            }
            node = stack.pop();
            list.add(node.val);
            node = node.right;
        }
        return list;
    }

    static class TreeNode{
        private int val;
        private TreeNode left;
        private TreeNode right;

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
}
