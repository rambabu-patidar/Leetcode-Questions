package com.LeetcodeQuestions.LinkedList;


public class PalindromeLL {
    private ListNode head;

    public PalindromeLL() {

    }

    // Link: https://leetcode.com/problems/palindrome-linked-list/submissions/

    // this is the better way we are reversing the second half
    // then comparing the first halves with the first and
    // then again reversing the second half to restore it as previous.
    // best method.
    public boolean isPalindrome1(ListNode head) {

         ListNode midNode = middleNode(head);
         ListNode reversedHead = reverseList(midNode);
         ListNode StoreReversedHead = reversedHead;
         ListNode node = head;
         while (node != null && reversedHead != null) {
             if( node.val != reversedHead.val) {
                 break;
             }
             node = node.next;
             reversedHead = reversedHead.next;
         }

         reverseList(StoreReversedHead);

         return node == null || reversedHead == null;
     }
     public ListNode reverseList(ListNode head) {
         ListNode node = head;
         ListNode prev = null;
         ListNode next;

         while (node != null) {
             next = node.next;
             node.next = prev;
             prev = node;
             node = next;
         }
         return prev;
     }

     public ListNode middleNode(ListNode head) {
         ListNode f = head;
         ListNode s = head;

         while (f != null && f.next != null) {
             f = f.next.next;
             s = s.next;
         }
         return s;
     }

    // this will take extra space as we are creating a new linked list
    // then reversing it and then comparing it.
    public boolean isPalindrome2(ListNode head) {
        if ( head == null || head.next == null) {
            return true;
        }
        ListNode node = head;
        ListNode revHead = new ListNode();
        ListNode temp = revHead;

        while (node != null) {
            temp.next = new ListNode(node.val);
            node = node.next;
            temp = temp.next;
        }
        revHead = reverse(revHead.next);
        temp = revHead;
        node = head;
        while (temp != null) {
            if (temp.val != node.val) {
                return false;
            }
            temp = temp.next;
            node = node.next;
        }
        return true;
    }
    private ListNode reverse(ListNode head) {
        if (head.next == null) {
            return head;
        }

        ListNode newHead = reverse(head.next);
        head.next.next = head;
        head.next = null;
        return newHead;
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
