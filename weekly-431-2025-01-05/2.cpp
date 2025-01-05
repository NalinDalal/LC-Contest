/* Q2. Find Mirror Score of a String
Medium
4 pt.
You are given a string s.

We define the mirror of a letter in the English alphabet as its corresponding
letter when the alphabet is reversed. For example, the mirror of 'a' is 'z', and
the mirror of 'y' is 'b'.

Initially, all characters in the string s are unmarked.

You start with a score of 0, and you perform the following process on the string
s:

Iterate through the string from left to right.
At each index i, find the closest unmarked index j such that j < i and s[j] is
the mirror of s[i]. Then, mark both indices i and j, and add the value i - j to
the total score. If no such index j exists for the index i, move on to the next
index without making any changes. Return the total score at the end of the
process.



Example 1:

Input: s = "aczzx"

Output: 5

Explanation:

i = 0. There is no index j that satisfies the conditions, so we skip.
i = 1. There is no index j that satisfies the conditions, so we skip.
i = 2. The closest index j that satisfies the conditions is j = 0, so we mark
both indices 0 and 2, and then add 2 - 0 = 2 to the score. i = 3. There is no
index j that satisfies the conditions, so we skip. i = 4. The closest index j
that satisfies the conditions is j = 1, so we mark both indices 1 and 4, and
then add 4 - 1 = 3 to the score. Example 2:

Input: s = "abcdef"

Output: 0

Explanation:

For each index i, there is no index j that satisfies the conditions.

 */

/* Key Observations
Mirror Property:
The mirror of a character s[i] is the character that satisfies:
s[i]+s[j]=′𝑎′+′𝑧′+1=219(ASCII values sum to 219)

For any character ch, its mirror can be calculated as:
mirror(𝑐ℎ)=chr(219−ord(𝑐ℎ))

Closest Pair: For each index i, find the closest unmarked index j (to the left
of i) such that 𝑠[𝑗] is the mirror of 𝑠[𝑖]. Marking:Once a pair (𝑖,𝑗) is found,
mark both indices i and j to ensure they are not reused. Score Calculation:Add
∣𝑖−𝑗∣ to the total score for every valid pair.*/

/* Algorithm
Iterate over the string from left to right.
For each character at index 𝑖, calculate its mirror.
Traverse backward from 𝑖−1 to find the closest unmarked index 𝑗 with the mirror
value. Mark both indices 𝑖 and 𝑗, and update the score with ∣𝑖−𝑗∣. Continue
until all indices are processed.*/

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int mirrorScore(string s) {
    int n = s.size();
    vector<bool> marked(n, false); // Track marked indices
    int score = 0;

    for (int i = 0; i < n; ++i) {
      if (marked[i])
        continue; // Skip already marked indices

      char mirrorChar = char(219 - s[i]); // Calculate mirror character
      for (int j = i - 1; j >= 0; --j) {  // Look for closest unmarked mirror
        if (!marked[j] && s[j] == mirrorChar) {
          // Mark indices and update score
          marked[i] = true;
          marked[j] = true;
          score += (i - j);
          break;
        }
      }
    }

    return score;
  }
};

// optimisation: use hashmap

class Solution2 {
public:
  long long calculateScore(string s) {
    unordered_map<char, vector<int>>
        charIndices; // Map to store unmarked indices for each character
    long long score = 0;

    for (int i = 0; i < s.size(); ++i) {
      char mirrorChar = char(219 - s[i]); // Calculate mirror character

      // Check if the mirror character exists with unmarked indices
      if (!charIndices[mirrorChar].empty()) {
        // Use the last (closest) index from the vector
        int j = charIndices[mirrorChar].back();
        charIndices[mirrorChar].pop_back(); // Remove the index from the list

        // Update score
        score += (i - j);
      } else {
        // Add the current index to the list for this character
        charIndices[s[i]].push_back(i);
      }
    }

    return score;
  }
};

// Example usage
int main() {
  Solution solution;
  cout << solution.mirrorScore("aczzx") << endl;  // Output: 5
  cout << solution.mirrorScore("abcdef") << endl; // Output: 0
  return 0;
}

// done
