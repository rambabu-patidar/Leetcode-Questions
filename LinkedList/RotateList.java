package com.LeetcodeQuestions.LinkedList;

public class RotateList {
    private ListNode head;

    public RotateList() {

    }

    // Leetcode: https://leetcode.com/problems/rotate-list/
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) {
            return null;
        }
        int length = lengthOfList(head);
        // number of times I have to rotate
        int r = k % length;

        // when after rotation we get the same list
        if ( r == 0) {
            return head;
        }
        ListNode last = getLast(head);
        ListNode prev = head;
        int pos = length - r - 1;
        while (pos >= 1) {
            prev = prev.next;
            pos--;
        }
        last.next = head;
        head = prev.next;
        prev.next = null;
        return head;
    }

    private ListNode getLast(ListNode head) {
        ListNode last = head;

        while (last.next != null) {
            last = last.next;
        }
        return last;
    }

    private int lengthOfList(ListNode head) {
        ListNode node = head;
        int length = 0;
        while (node != null) {
            length += 1;
            node = node.next;
        }
        return length;
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
