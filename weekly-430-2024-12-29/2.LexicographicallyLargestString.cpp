/*
https://leetcode.com/contest/weekly-contest-430/problems/find-the-lexicographically-largest-string-from-the-box-i/

Q2. Find the Lexicographically Largest String From the Box I
Medium
4 pt.
You are given a string word, and an integer numFriends.

Alice is organizing a game for her numFriends friends. There are multiple rounds
in the game, where in each round:

word is split into numFriends non-empty strings, such that no previous round has
had the exact same split. All the split words are put into a box. Find the
lexicographically largest string from the box after all the rounds are finished.

A string a is lexicographically smaller than a string b if in the first position
where a and b differ, string a has a letter that appears earlier in the alphabet
than the corresponding letter in b. If the first min(a.length, b.length)
characters do not differ, then the shorter string is the lexicographically
smaller one.



Example 1:

Input: word = "dbca", numFriends = 2

Output: "dbc"

Explanation:

All possible splits are:

"d" and "bca".
"db" and "ca".
"dbc" and "a".
Example 2:

Input: word = "gggg", numFriends = 4

Output: "g"

Explanation:

The only possible split is: "g", "g", "g", and "g".



Constraints:

1 <= word.length <= 5 * 103
word consists only of lowercase English letters.
1 <= numFriends <= word.length*/

// what to do:

// Iterate over all possible ways to split word into numFriends parts.
// Extract the first part of each split.
// Track the lexicographically largest first part.

/*class Solution {
public:
  string answerString(string word, int numFriends) {
    sort(word.begin(), word.end());
    string ans = "";
    for (int i = 0; i < numFriends.length; i++) {
      ans += word[i];
    }
    return ans;
  }
};*/

/*class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        string largest = "";

        // Generate all possible first parts for numFriends splits
        for (int i = 1; i <= n - numFriends + 1; ++i) {
            string firstPart = word.substr(0, i);
            largest = max(largest, firstPart);
        }

        return largest;
    }
};
*/

/* Correct Plan:
Generate All Valid Splits:

Split the string word into numFriends non-empty parts, iterating over all
possible divisions. Each split must divide the string into exactly numFriends
parts. Track Lexicographically Largest Part:

For each split, check all parts and keep track of the largest string
encountered. Visualization Support:

Break the problem into parts to help visualize how splits are generated and how
comparisons are performed.*/

/*#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        string largest = "";

        // Helper function to generate splits
        function<void(int, vector<string>&)> dfs = [&](int start,
vector<string>& current) {
            // Base case: numFriends splits achieved
            if (current.size() == numFriends) {
                if (start == n) { // Valid split if we've used the whole string
                    for (const string& part : current) {
                        largest = max(largest, part); // Update largest part
                    }
                }
                return;
            }

            // Generate parts starting at `start`
            for (int i = start; i < n; ++i) {
                current.push_back(word.substr(start, i - start + 1)); // Add
part dfs(i + 1, current); // Recur for next part current.pop_back(); //
Backtrack
            }
        };

        vector<string> current;
        dfs(0, current);
        return largest;
    }
};
//tle
*/

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string answerString(string word, int numFriends) {
    int n = word.size();
    vector<vector<string>> dp(n + 1,
                              vector<string>(numFriends + 1, "")); // DP table

    // Base case: 0 parts = empty string
    for (int i = 0; i <= n; ++i) {
      dp[i][0] = "";
    }

    // DP to compute the solution
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= numFriends; ++j) {
        // Split the string into `j` parts
        for (int k = 0; k < i; ++k) {                 // k is the split point
          string currentPart = word.substr(k, i - k); // Get the current part
          if (dp[k][j - 1] != "") { // Check if previous split exists
            dp[i][j] = max(dp[i][j], max(dp[k][j - 1], currentPart));
          }
        }
      }
    }

    // The answer is the lexicographically largest part
    return dp[n][numFriends];
  }
};

// leae for now
