package com.LeetcodeQuestions.LinkedList;

public class DeleteNodeWithoutHead {
    private ListNode head;

    public DeleteNodeWithoutHead() {

    }

//    Q. https://leetcode.com/problems/delete-node-in-a-linked-list/

    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
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
