/* Q2. Longest Palindromic Subsequence After at Most K Operations
Medium
4 pt.
You are given a string s and an integer k.

In one operation, you can replace the character at any position with the next or
previous letter in the alphabet (wrapping around so that 'a' is after 'z'). For
example, replacing 'a' with the next letter results in 'b', and replacing 'a'
with the previous letter results in 'z'. Similarly, replacing 'z' with the next
letter results in 'a', and replacing 'z' with the previous letter results in
'y'.

Return the length of the longest palindromic subsequence of s that can be
obtained after performing at most k operations.

A subsequence is a non-empty string that can be derived from another string by
deleting some or no characters without changing the order of the remaining
characters.

A palindrome is a string that reads the same forward and backward.



Example 1:

Input: s = "abced", k = 2

Output: 3

Explanation:

Replace s[1] with the next letter, and s becomes "acced".
Replace s[4] with the previous letter, and s becomes "accec".
The subsequence "ccc" forms a palindrome of length 3, which is the maximum.

Example 2:

Input: s = "aaazzz", k = 4

Output: 6

Explanation:

Replace s[0] with the previous letter, and s becomes "zaazzz".
Replace s[4] with the next letter, and s becomes "zaazaz".
Replace s[3] with the next letter, and s becomes "zaaaaz".
The entire string forms a palindrome of length 6.



Constraints:

1 <= s.length <= 200
1 <= k <= 200
s consists of only lowercase English letters.*/
#include <string>
#include <vector>
using namespace std;

// return length of almost palindromic string after k operations
// 1. Use dynamic programming (DP) to compute the longest palindromic
// subsequence (LPS).
// 2. Determine if k Modifications Can Improve It
// If the difference between the original string length and LPS is ≤ k, we
// can turn the entire string into a palindrome. else LPS+k

class Solution {
public:
  int cost(char a, char b) {
    int diff = abs(a - b);
    return min(diff, 26 - diff);
  }

  int dp(int i, int j, int rem, const string &s,
         vector<vector<vector<int>>> &memo) {
    if (i > j)
      return 0;
    if (i == j)
      return 1;
    if (memo[i][j][rem] != -1)
      return memo[i][j][rem];
    int res = max(dp(i + 1, j, rem, s, memo), dp(i, j - 1, rem, s, memo));
    int c = cost(s[i], s[j]);
    if (c <= rem)
      res = max(res, dp(i + 1, j - 1, rem - c, s, memo) + 2);
    memo[i][j][rem] = res;
    return res;
  }

  int longestPalindromicSubsequence(string s, int k) {
    int n = s.size();
    vector<vector<vector<int>>> memo(
        n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
    return dp(0, n - 1, k, s, memo);
  }
};

// not solved
