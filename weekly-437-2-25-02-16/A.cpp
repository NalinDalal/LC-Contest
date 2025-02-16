/* Q1. Find Special Substring of Length K
Easy
3 pt.
You are given a string s and an integer k.

Determine if there exists a substring of length exactly k in s that satisfies
the following conditions:

The substring consists of only one distinct character (e.g., "aaa" or "bbb").
If there is a character immediately before the substring, it must be different
from the character in the substring. If there is a character immediately after
the substring, it must also be different from the character in the substring.
Return true if such a substring exists. Otherwise, return false.

A substring is a contiguous non-empty sequence of characters within a string.


Example 1:

Input: s = "aaabaaa", k = 3

Output: true

Explanation:

The substring s[4..6] == "aaa" satisfies the conditions.

It has a length of 3.
All characters are the same.
The character before "aaa" is 'b', which is different from 'a'.
There is no character after "aaa".
Example 2:

Input: s = "abc", k = 2

Output: false

Explanation:

There is no substring of length 2 that consists of one distinct character and
satisfies the conditions.



Constraints:

1 <= k <= s.length <= 100
s consists of lowercase English letters only.*/

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
  bool hasSpecialSubstring(string s, int k) {
    // k length ki substr in s
    // substr has only one distinct char
    // char b/f substr start is diff
    // diff char a/f substr

    // Check if string is long enough for k-length substring plus chars
    // before/after

    // Check each possible starting position for k-length substring
    // We stop at length-k-1 to ensure there's space for char after substring
    int n = s.length();
    if (n < k)
      return false; // If s is shorter than k, no valid substring

    for (int i = 0; i <= n - k; i++) { // Correct loop condition
      // Check if substring from index i to i + k - 1 has only one distinct
      // character
      char firstChar = s[i];
      bool isOneChar = true;
      for (int j = i; j < i + k; j++) {
        if (s[j] != firstChar) {
          isOneChar = false;
          break;
        }
      }

      if (isOneChar) {
        // Edge case: No character before the substring
        if (i > 0 && s[i - 1] == firstChar)
          continue;

        // Edge case: No character after the substring
        if (i + k < n && s[i + k] == firstChar)
          continue;

        return true;
      }
    }

    return false;
  }
};
// accepted

int main() {
  string s1 = "aaabaaa";
  int k1 = 3;
  string s2 = "abc";
  int k2 = 2;

  Solution obj;
  cout << s1 << " " << k1 << endl;
  cout << obj.hasSpecialSubstring(s1, k1) << endl;

  cout << endl;
  cout << s2 << " " << k2 << endl;
  cout << obj.hasSpecialSubstring(s2, k2) << endl;
}

// sub:
// https://leetcode.com/contest/weekly-contest-437/problems/find-special-substring-of-length-k/submissions/1544549446/?slug=length-of-longest-v-shaped-diagonal-segment&region=global_v2
