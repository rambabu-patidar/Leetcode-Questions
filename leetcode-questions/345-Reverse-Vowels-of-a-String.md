
# 345. Reverse Vowels of a String (Easy)
## Problem:

#### [problem link](https://leetcode.com/problems/reverse-string/)
Given a string `s`, reverse only all the vowels in the string and return it.

The vowels are `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`, and they can appear in both lower and upper cases, more than once.

**Example 1:**

```
Input: s = "hello"
Output: "holle"
```

**Example 2:**

```
Input: s = "leetcode"
Output: "leotcede"
```

**Constraints:**

- `1 <= s.length <= 3 * 105`
- `s` consist of **printable ASCII** characters.


## Solution:

This is very extension of the [344. Reverse String](https://leetcode.com/problems/reverse-string/) question.

In previous question we used two pointer to swap every character until the pointer does not met. 
similarly we will use two pointer and only swap if both the pointer are pointing to vowels . To make the pointers point to vowels we check every chracter from start and from backward and moves start ahead and end backward untill both the start and end are pointing to vowel and then we will swap the character.

### Code:

```c++
class Solution {
public:

    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U') {
            return true;
        } else {
            return false;
        }
    }
    string reverseVowels(string s) {
        int start = 0;
        int end = s.length() -1;
        while (start < end) {
            while (start < end && !isVowel(s[start])) {
                start++;
            } 
            while (start < end && !isVowel(s[end])) {
                end--;
            }

            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++; end--;
        }

        return s;
    }
};
```
