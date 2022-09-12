package com.LeetcodeQuestions.Recursion;

// Best approach below:
//Q. https://leetcode.com/problems/permutations/

import java.util.ArrayList;
import java.util.List;

public class Permutations {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3};
        System.out.println(permute(arr));
    }

    public static List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> list = new ArrayList<>();
        return helper(nums, 0, new ArrayList<>(3));
    }

    private static List<List<Integer>> helper(int[] nums, int i, List<Integer> up) {
        List<List<Integer>> list = new ArrayList<>();
        if (i == nums.length) {
            // we need to create store list as if we directly add up(unprocessed) list then

            // the object will get changed every time when we are removing from the
            // last element inserted.
            // because of the fact that there is only one object of up list in whole
            // recursion call as we passed it in argument.
            List<Integer> store = new ArrayList<>(up);
            list.add(store);
            return list;
        }

        int size = up.size();
        for (int j = 0; j <= size; j++) {
             up.add(j,nums[i]);
             List<List<Integer>> innerList = helper(nums, i + 1, up);
             list.addAll(innerList);
             up.remove(j); // this remove the last element we added in it
        }
        return list;
    }
}


/*
class Solution {
    public List<List<Integer>> permute(int[] nums) {

        List<List<Integer>>ans = new ArrayList<>();

        generatepermute2(0,nums,ans);
        return ans;

    }

    public static void generatepermute2(int idx, int []nums,List<List<Integer>>ans) {

        if(idx == nums.length){
            List<Integer>ds = new ArrayList<>();
            for(int x : nums){
                ds.add(x);
            }
            ans.add(ds);
            return;
        }




        for(int i=idx;i<nums.length;i++){
            swap(i,idx,nums);
            generatepermute2(idx+1, nums, ans);
            swap(i,idx,nums);

        }



    }

     public static void swap(int i,int j, int[]nums){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;

    }
}
 */
