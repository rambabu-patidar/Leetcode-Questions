package com.LeetcodeQuestions.Arrays;

// Q. https://leetcode.com/problems/count-primes/

public class SieveOfEratosthenes {
    public static void main(String[] args) {

    }

    public static int countPrimes(int n) {
        boolean[] data = new boolean[n];
        sieve(data);
        int count = 0;
        for (int i = 1; i < data.length; i++) {
            if (data[i] == false) {
                count++;
            }
        }

        return count;
    }

    public static void sieve(boolean[] data) {

        for (int i = 1; i * i < data.length; i++) {

            if (data[i] == false) {
                int j = i;
                while (j < data.length) {
                    data[j] = true;
                    j += i + 1;
                }
                data[i + 1] = false;
            }
        }
    }
}
