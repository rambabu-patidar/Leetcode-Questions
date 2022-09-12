// !!simple

package com.LeetcodeQuestions.LinkedList;

public class RemoveDuplicate {
    private ListNode head;

    public RemoveDuplicate() {

    }
    // Q. https://leetcode.com/problems/remove-duplicates-from-sorted-list/
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode node = head;
        while (node.next != null) {
            if (node.val == node.next.val) {
                node.next = node.next.next;
            } else{
                node = node.next;
            }
        }
        return head;
    }
    private class ListNode {
        private int val;
        private ListNode next;

        public ListNode() {
            // default constructor
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
