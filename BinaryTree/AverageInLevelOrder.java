package com.LeetcodeQuestions.BinaryTree;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class AverageInLevelOrder {
    TreeNode root;

    public AverageInLevelOrder() {
    }

//    Q. https://leetcode.com/problems/average-of-levels-in-binary-tree/

    public List<Double> averageOfLevels(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        queue.add(null);
        List<Double> list = new ArrayList<>();
        double sum = 0;
        double count = 0;
        while (!queue.isEmpty()) {
            TreeNode node = queue.remove();

            if (node != null) {
                sum += node.val;
                count++;
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            } else if (!queue.isEmpty()) {
                queue.add(null);
                list.add(sum / count);
                sum = 0;
                count = 0;
            }
        }
        list.add(sum / count);
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
