package com.LeetcodeQuestions.LinkedList;

public class MergeSorted {
    private ListNode head;

    public MergeSorted() {

    }

    // Leetcode : https://leetcode.com/problems/merge-two-sorted-lists/

    public ListNode mergeSorted(ListNode head1, ListNode head2) {
        ListNode f = head1;
        ListNode s = head2;

        ListNode newHead = new ListNode();
        ListNode node = newHead;
        while (f != null && s != null) {
            if (f.val < s.val) {
                node.next = new ListNode(f.val);
                f = f.next;
            } else {
                node.next = new ListNode(s.val);
                s = s.next;
            }
            node = node.next;
        }

        while (f != null) {
            node.next = new ListNode(f.val);
            f = f.next;
            node = node.next;
        }

        while (s != null) {
            node.next = new ListNode(s.val);
            s = s.next;
            node = node.next;
        }
        return newHead.next;
    }

    private class ListNode {
        private int val;
        private ListNode next;

        public ListNode() {
            // default constructor
        }
        // creating node and passing value equals val and next null
        public ListNode(int val) {
            this.val = val;
        }
        // creating node and passing value equals val and next also
        public ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }
}
