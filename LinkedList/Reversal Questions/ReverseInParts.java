package com.LeetcodeQuestions.LinkedList;

public class ReverseInParts {
    private ListNode head;

    public ReverseInParts() {

    }
    // https://leetcode.com/problems/reverse-linked-list-ii/submissions/

    public ListNode reverseInPart(ListNode head, int left, int right) {
        if (left == right) {
            return head;
        }

        // reaching till left
        ListNode prevLeft = null;
        ListNode node = head;
        for (int i = 1; i < left ; i++) {
            prevLeft = node;
            node = node.next;
        }

        // reversing in-place
        ListNode prev = prevLeft;
        ListNode next = node.next;
        for (int i = 1; i <= right - left + 1 ; i++) {
            next = node.next;
            node.next = prev;
            prev = node;
            node = next;
        }
        // if it starts from head than head will change
        if (prevLeft == null) {
            head.next = next;
            head = prev;
        } else { // if it starts from between head will not chage
            prevLeft.next.next = next;
            prevLeft.next =prev;
        }
        return head;
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
