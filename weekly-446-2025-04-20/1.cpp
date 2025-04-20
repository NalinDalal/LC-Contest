/*
Q1. Calculate Score After Performing Instructions
Medium
4 pt.
You are given two arrays, instructions and values, both of size n.

You need to simulate a process based on the following rules:

You start at the first instruction at index i = 0 with an initial score of 0.
If instructions[i] is "add":
Add values[i] to your score.
Move to the next instruction (i + 1).
If instructions[i] is "jump":
Move to the instruction at index (i + values[i]) without modifying your score.
The process ends when you either:

Go out of bounds (i.e., i < 0 or i >= n), or
Attempt to revisit an instruction that has been previously executed. The
revisited instruction is not executed. Return your score at the end of the
process.



Example 1:

Input: instructions = ["jump","add","add","jump","add","jump"], values =
[2,1,3,1,-2,-3]

Output: 1

Explanation:

Simulate the process starting at instruction 0:

At index 0: Instruction is "jump", move to index 0 + 2 = 2.
At index 2: Instruction is "add", add values[2] = 3 to your score and move to
index 3. Your score becomes 3. At index 3: Instruction is "jump", move to index
3 + 1 = 4. At index 4: Instruction is "add", add values[4] = -2 to your score
and move to index 5. Your score becomes 1. At index 5: Instruction is "jump",
move to index 5 + (-3) = 2. At index 2: Already visited. The process ends.
Example 2:

Input: instructions = ["jump","add","add"], values = [3,1,1]

Output: 0

Explanation:

Simulate the process starting at instruction 0:

At index 0: Instruction is "jump", move to index 0 + 3 = 3.
At index 3: Out of bounds. The process ends.
Example 3:

Input: instructions = ["jump"], values = [0]

Output: 0

Explanation:

Simulate the process starting at instruction 0:

At index 0: Instruction is "jump", move to index 0 + 0 = 0.
At index 0: Already visited. The process ends.


Constraints:

n == instructions.length == values.length
1 <= n <= 105
instructions[i] is either "add" or "jump".
-105 <= values[i] <= 105*/

#include <bits/stdc++.h>
using namespace std;

/* - Maintain a variable score to keep track of the score.

- Use a visited set or boolean array to track which instructions have been
executed.

- Start from i = 0, and in each step:

    - If the instruction is already visited or i is out of bounds, terminate.

    - Mark the instruction as visited.

    - If it's an "add" instruction:
        - Add values[i] to score, move to i + 1.

    - If it's a "jump" instruction:
        - Move to i + values[i]. */
class Solution {
public:
  long long calculateScore(vector<string> &instructions, vector<int> &values) {
    int n = instructions.size();
    vector<bool> visited(n, false);
    long long score = 0;
    int i = 0;

    while (i >= 0 && i < n && !visited[i]) {
      visited[i] = true;
      if (instructions[i] == "add") {
        score += values[i];
        i += 1;
      } else if (instructions[i] == "jump") {
        i += values[i];
      }
    }

    return score;
  }
};
// sub:
// https://leetcode.com/contest/weekly-contest-446/problems/calculate-score-after-performing-instructions/submissions/1612029271/
