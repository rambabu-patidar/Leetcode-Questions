// !!IMPORTANT

package com.LeetcodeQuestions.LinkedList;

public class PartitionList {
    ListNode head;

    public PartitionList() {
    }
    // Q. https://leetcode.com/problems/partition-list/

    public ListNode partition(ListNode head, int x) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode node = head;
        ListNode sHead = new ListNode();
        ListNode lHead = new ListNode();
        ListNode sNode = sHead;
        ListNode lNode = lHead;

        while (node != null) {
            if (node.val < x) {
                sNode.next = node;
                sNode = sNode.next;
            } else {
                lNode.next = node;
                lNode = lNode.next;
            }
            node = node.next;
        }
        sNode.next = null;
        lNode.next = null;
        sNode.next = lHead.next;
        return sHead.next;
    }
    private class ListNode{
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
