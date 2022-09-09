package com.LeetcodeQuestions.LinkedList;

// removes all the element of the given value from linked list

public class RemoveLinkedListElements {
    private ListNode head;

    public RemoveLinkedListElements() {

    }

    // https://leetcode.com/problems/remove-linked-list-elements/submissions/

    public ListNode removeElements(ListNode head, int val) {
        if (head == null) {
            return null;
        }

        ListNode node = head;
        ListNode prev = null;

        while (node != null) {
            boolean isNull = false;
            if (node.val == val) {
                isNull = true;
                if (prev == null) {
                    head = head.next;
                } else {
                    prev.next = node.next;
                }
            }
            if (!isNull) {
                prev = node;
            }
            node = node.next;
        }
        return head;
    }

    private class ListNode {
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
