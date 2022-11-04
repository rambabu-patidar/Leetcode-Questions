package com.LeetcodeQuestions;

import java.util.Stack;

public class NextGreaterElementI {
    public static void main(String[] args) {

    }

    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        // since the number of element in the nums1 or nums2 will be
        // less than 1001. create an array of size 1001
        int[] nge = new int[1001];
        int size = nums2.length;
        Stack<Integer> stack = new Stack<Integer>();
        for (int i = size - 1 ; i >= 0; i--) {

            while (!stack.isEmpty() && nums2[i] > stack.peek()) {
                stack.pop();
            }

            if (stack.isEmpty()) {
                nge[nums2[i]] = -1;
            } else {
                nge[nums2[i]] = stack.peek();
            }
            stack.push(nums2[i]);
        }
        int[] ans = new int[nums1.length];
        for (int i = 0; i < nums1.length; i++) {
            ans[i] = nge[nums1[i]];
        }
        return ans;
    }
}
