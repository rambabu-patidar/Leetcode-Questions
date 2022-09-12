package com.LeetcodeQuestions.Arrays;
import java.util.Arrays;

// Q. https://leetcode.com/problems/distribute-candies-to-people/

public class CandiesDistribution {

    public static void main(String[] args) {
        System.out.println(Arrays.toString(distributeCandies(20,5)));
    }
    public static int[] distributeCandies(int candies, int num_people) {
        int i = 0 ;
        int[] ans = new int[num_people];

        while (candies > 0) {
            if (candies >  i + 1) {
                ans[i % num_people] += i+1;
                candies -= i+ 1;
                i++;
            }
            else {
                ans[i % num_people] += candies;
                break;
            }
        }

        return ans;
    }
}
