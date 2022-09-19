package com.LeetcodeQuestions.BinaryTree;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class LevelOrder {
    TreeNode root;

    public LevelOrder() {
    }

//    Q. https://leetcode.com/problems/binary-tree-level-order-traversal/
//    Q. https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) {
            return new ArrayList<>(new ArrayList<>());
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        List<List<Integer>> list = new ArrayList<>();

        while (!queue.isEmpty()) {
            int n = queue.size();
            List<Integer> subLists = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                TreeNode node = queue.remove();

                subLists.add(node.val);

                if (node.left != null) {
                    queue.add(node.left);
                }
                if(node.right != null) {
                    queue.add(node.right);
                }
            }
            list.add(subLists);
        }

        // uncomment this to solve the second question
//        int size = list.size();
//        for (int i =0 ; i<size / 2; i++) {
//            List<Integer> temp = list.get(i);
//            list.set(i, list.get(size - 1 - i));
//            list.set(size - 1 - i, temp);
//        }
        return list;
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
}
