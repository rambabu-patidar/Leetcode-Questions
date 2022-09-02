package com.LeetcodeQuestions.LinkedList;

public class AddTwoNumbers {
    private ListNode head;

    public AddTwoNumbers() {

    }
    // 2. https://leetcode.com/problems/add-two-numbers/

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode node1 = l1;
        ListNode node2 = l2;
        ListNode newHead = new ListNode();
        ListNode node3;
        ListNode prev = null;;

        int carry = 0;

        while ( node1 != null && node2 != null) {
            int sum = node1.val + node2.val;
            node3 = new ListNode((sum + carry) % 10);
            if (node1 == l1) {
                newHead = node3;
            }
            if (node3 != newHead) {
                prev.next = node3;
            }
            prev = node3;
            carry = (sum + carry) / 10;
            node1 = node1.next;
            node2 = node2.next;

        }

        while(node1 != null) {
            int sum = node1.val;
            node3 = new ListNode((sum + carry) % 10);
            if (node3 != newHead) {
                prev.next = node3;
            }
            prev = node3;
            carry = (sum + carry) / 10;
            node1 = node1.next;

        }

        while( node2 != null) {
            int sum = node2.val;
            node3 = new ListNode((sum + carry) % 10);
            if (node3 != newHead) {
                prev.next = node3;
            }
            prev = node3;
            carry = (sum + carry) / 10;
            node2 = node2.next;
        }

        if (carry != 0){
            node3 = new ListNode(carry);
            prev.next = node3;
        }
        return newHead;

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
