package com.LeetcodeQuestions.LinkedList;

public class MergeSortOnLL {
    private ListNode head;

    MergeSortOnLL() {

    }

    // Leetcode: https://leetcode.com/problems/sort-list/
    public ListNode sortList(ListNode head) {
        if (head.next == null) {
            return head;
        }

        ListNode midNode = getMid(head, 1); // we want first mid.

        ListNode midHead = midNode.next; // making the second list head
        midNode.next = null; // making first list last node to point to null

        ListNode head1 = sortList(head);
        ListNode head2 = sortList(midHead);

        return mergeSorted(head1,head2);
    }

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

    private ListNode getMid(ListNode head, int first) {
        ListNode f = head;
        ListNode s = head;
        ListNode fMid = head;
        while (f != null && f.next != null) {
            f = f.next.next;
            fMid = s;
            s = s.next;
        }
        return fMid;
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
