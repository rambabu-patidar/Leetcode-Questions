package com.LeetcodeQuestions.LinkedList;

public class FindCycleNode {
    private ListNode head;

    public FindCycleNode() {

    }

    // https://leetcode.com/problems/linked-list-cycle-ii/

    private ListNode hasCycle(ListNode head) {
        ListNode f = head;
        ListNode s = head;
        do {
            if (f == null || f.next == null) {
                return null;
            }
            f = f.next.next;
            s = s.next;
        } while (f != s);
        return f;
    }

    public ListNode detectCycle(ListNode head) {
        ListNode f = hasCycle(head);
        if (f == null) {
            return null;
        } else {
            ListNode s = head;

            while (f != s ) {
                f = f.next;
                s = s.next;
            }
            return f;
        }
    }

    private int lengthOfCycle(ListNode f) {
        ListNode s = f;
        int length = 0;
        do {
            length++;
            s = s.next;
        } while (s != f);
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
