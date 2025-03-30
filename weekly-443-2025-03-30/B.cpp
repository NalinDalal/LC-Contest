/*Q2. Longest Palindrome After Substring Concatenation I
Medium
4 pt.
You are given two strings, s and t.

You can create a new string by selecting a substring from s (possibly empty) and
a substring from t (possibly empty), then concatenating them in order.

Return the length of the longest palindrome that can be formed this way.

A substring is a contiguous sequence of characters within a string.

A palindrome is a string that reads the same forward and backward.



Example 1:

Input: s = "a", t = "a"

Output: 2

Explanation:

Concatenating "a" from s and "a" from t results in "aa", which is a palindrome
of length 2.

Example 2:

Input: s = "abc", t = "def"

Output: 1

Explanation:

Since all characters are different, the longest palindrome is any single
character, so the answer is 1.

Example 3:

Input: s = "b", t = "aaaa"

Output: 4

Explanation:

Selecting "aaaa" from t is the longest palindrome, so the answer is 4.

Example 4:

Input: s = "abcde", t = "ecdba"

Output: 5

Explanation:

Concatenating "abc" from s and "ba" from t results in "abcba", which is a
palindrome of length 5.



Constraints:

1 <= s.length, t.length <= 30
s and t consist of lowercase English letters.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValid(string sb) {
    int n = sb.size();
    for (int i = 0; i < n / 2; i++) {
      if (sb[i] != sb[n - i - 1])
        return false;
    }
    return true;
  }
  int longestPalindrome(string s, string t) {
    int n = s.size(), m = t.size(), ans = 0;
    for (int i = 0; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        string sub_s = s.substr(i, j);
        for (int k = 0; k <= m; k++) {
          for (int l = 0; l <= m; l++) {
            string sub_t = t.substr(k, l);
            string combined_str = sub_s + sub_t;
            if (isValid(combined_str)) {
              ans = max(ans, combined_str.length());
            }
          }
        }
      }
    }
    return ans;
  }
};
/*
class Solution:
    def isValid(self, sb: str) -> bool:
        return sb == sb[::-1]  # Check if the string is a palindrome

    def longestPalindrome(self, s: str, t: str) -> int:
        n, m = len(s), len(t)
        ans = 0

        # Iterate over all substrings of s
        for i in range(n + 1):
            for j in range(i, n + 1):
                sub_s = s[i:j]  # Substring of s

                # Iterate over all substrings of t
                for k in range(m + 1):
                    for l in range(k, m + 1):
                        sub_t = t[k:l]  # Substring of t
                        combined_str = sub_s + sub_t  # Concatenate both
substrings

                        if self.isValid(combined_str):
                            ans = max(ans, len(combined_str))

        return ans
*/
