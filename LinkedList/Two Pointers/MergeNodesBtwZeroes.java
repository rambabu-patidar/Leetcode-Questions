package com.LeetcodeQuestions;

public class MergeNodesBtwZeroes {

    private ListNode head;

    public MergeNodesBtwZeroes() {
    }
//    Q. https://leetcode.com/problems/merge-nodes-in-between-zeros/

    public ListNode mergeNodes(ListNode head) {
        // Don't require the base condition because the number of nodes
        // in the constraints are given to be greater than 3
        ListNode node = head.next;
        ListNode temp = head;

        while (node != null){
            int sum = 0;
            do {
                sum += node.val;
                node = node.next;
            } while (node.val != 0);

            temp.val = sum;
            node = node.next;
            if (node != null) {
                temp = temp.next;
            }
        }
        temp.next = null;
        return head;
    }

    public class ListNode{
        private int val;
        private ListNode next;

        public ListNode() {
        }

        public ListNode(int val) {
            this.val = val;
        }

        public ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }
}
