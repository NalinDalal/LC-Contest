/* Q2. Smallest Palindromic Rearrangement I
Medium
4 pt.
You are given a palindromic string s.

Return the lexicographically smallest palindromic permutation of s.

A string is palindromic if it reads the same forward and backward.

A permutation is a rearrangement of all the characters of a string.

A string a is lexicographically smaller than a string b if in the first position
where a and b differ, string a has a letter that appears earlier in the alphabet
than the corresponding letter in b. If the first min(a.length, b.length)
characters do not differ, then the shorter string is the lexicographically
smaller one.


Example 1:

Input: s = "z"

Output: "z"

Explanation:

A string of only one character is already the lexicographically smallest
palindrome.

Example 2:

Input: s = "babab"

Output: "abbba"

Explanation:

Rearranging "babab" → "abbba" gives the smallest lexicographic palindrome.

Example 3:

Input: s = "daccad"

Output: "acddca"

Explanation:

Rearranging "daccad" → "acddca" gives the smallest lexicographic palindrome.



Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
s is guaranteed to be palindromic.*/

// given string s{palindrome}
// permutation string must be palindrome
// it must be lexicographically smaller
// return the permutation string

/*Count character frequencies in s.

Check if a palindromic permutation is possible:

If the string length is even: all character frequencies must be even.

If the string length is odd: exactly one character may have an odd frequency.

Construct the palindrome:

Sort the characters.

Build the first half using half of each character's frequency.

If there's a middle character (odd count), store it separately.

Build the second half as the reverse of the first half.
*
*/
class Solution {
public:
  string smallestPalindrome(string s) {
    unordered_map<char, int> freq;
    for (char c : s)
      freq[c]++;

    int oddCount = 0;
    char midChar = 0;
    for (auto [c, count] : freq) {
      if (count % 2 == 1) {
        oddCount++;
        midChar = c;
      }
    }

    if ((s.size() % 2 == 0 && oddCount > 0) ||
        (s.size() % 2 == 1 && oddCount != 1))
      return ""; // impossible to form palindromic permutation

    string firstHalf = "";
    vector<char> keys;
    for (auto &[c, _] : freq)
      keys.push_back(c);
    sort(keys.begin(), keys.end());

    for (char c : keys) {
      firstHalf += string(freq[c] / 2, c);
    }

    string secondHalf = firstHalf;
    reverse(secondHalf.begin(), secondHalf.end());

    return (midChar ? firstHalf + midChar + secondHalf
                    : firstHalf + secondHalf);
  }
};
// sub:
// https://leetcode.com/contest/weekly-contest-445/problems/smallest-palindromic-rearrangement-i/submissions/1605137204/?slug=find-closest-person&region=global_v2
