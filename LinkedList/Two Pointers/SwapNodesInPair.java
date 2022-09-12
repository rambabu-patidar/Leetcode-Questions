package com.LeetcodeQuestions.LinkedList;

public class SwapNodesInPair {
    private ListNode head;

    public SwapNodesInPair() {

    }

    public ListNode swapPairs(ListNode head) {
        // when head is null;
        // or it has only one element
        if( head == null || head.next == null ){
            return head;
        }

        ListNode f = head;
        ListNode s = head.next;
        ListNode prev = null;


        while (s != null) {
            f.next = s.next;
            s.next = f;
            if (prev != null) {
                prev.next = s;
            } else {
                head = s;
            }


            prev = f;
            if (s.next.next != null) {
                s = s.next.next.next;
            }else {
                s = null;
            }

            f = f.next;
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
