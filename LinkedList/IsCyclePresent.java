package com.LeetcodeQuestions.LinkedList;

public class IsCyclePresent {
    private ListNode head;

    public IsCyclePresent() {

    }

    // https://leetcode.com/problems/linked-list-cycle/

    public boolean hasCycle(ListNode head) {
        ListNode f = head;
        ListNode s = head;

        do {
            if (f == null || f.next == null) {
                return false;
            }
            f = f.next.next;
            s = s.next;
        } while (f != s);
        return true;
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
