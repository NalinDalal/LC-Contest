/* https://leetcode.com/contest/weekly-contest-436/problems/sort-matrix-by-diagonals/?slug=sort-matrix-by-diagonals&region=global_v2
Q1. Sort Matrix by Diagonals
Medium
3 pt.
You are given an n x n square matrix of integers grid. Return the matrix such
that:

The diagonals in the bottom-left triangle (including the middle diagonal) are
sorted in non-increasing order. The diagonals in the top-right triangle are
sorted in non-decreasing order.


Example 1:

Input: grid = [[1,7,3],[9,8,2],[4,5,6]]

Output: [[8,2,3],[9,6,7],[4,5,1]]

Explanation:



The diagonals with a black arrow (bottom-left triangle) should be sorted in
non-increasing order:

[1, 8, 6] becomes [8, 6, 1].
[9, 5] and [4] remain unchanged.
The diagonals with a blue arrow (top-right triangle) should be sorted in
non-decreasing order:

[7, 2] becomes [2, 7].
[3] remains unchanged.
Example 2:

Input: grid = [[0,1],[1,2]]

Output: [[2,1],[1,0]]

Explanation:



The diagonals with a black arrow must be non-increasing, so [0, 2] is changed to
[2, 0]. The other diagonals are already in the correct order.

Example 3:

Input: grid = [[1]]

Output: [[1]]

Explanation:

Diagonals with exactly one element are already in order, so no changes are
needed.



Constraints:

grid.length == grid[i].length == n
1 <= n <= 10
-105 <= grid[i][j] <= 105
*/

class Solution {
public:
  vector<vector<int>> sortMatrix(vector<vector<int>> &grid) {
    // sort the diagonal row in descending order
    // return the matrix after operations
    // sort the upper triangle in non-decreasing
    if (grid.size() == 1)
      return grid;
    // it's always n*n
    // First, sort all diagonals in descending order.
    // Then, extract the upper triangle elements, sort them in non-decreasing
    // order, and place them back.
    int n = grid.size();
    // Sorting diagonals in descending order
    for (int i = 0; i < n; i++) {
      vector<int> diag;
      int r = i, c = 0;
      while (r < n && c < n) {
        diag.push_back(grid[r][c]);
        r++;
        c++;
      }
      sort(diag.rbegin(), diag.rend()); // Sort in descending order
      r = i, c = 0;
      for (int val : diag) {
        grid[r][c] = val;
        r++;
        c++;
      }
    }
    for (int j = 1; j < n; j++) {
      vector<int> diag;
      int r = 0, c = j;
      while (r < n && c < n) {
        diag.push_back(grid[r][c]);
        r++;
        c++;
      }
      sort(diag.rbegin(), diag.rend());
      r = 0, c = j;
      for (int val : diag) {
        grid[r][c] = val;
        r++;
        c++;
      }
    }

    // Sorting the upper triangle in non-decreasing order
    vector<int> upperTriangle;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        upperTriangle.push_back(grid[i][j]);
      }
    }
    sort(upperTriangle.begin(), upperTriangle.end());

    // Putting sorted elements back
    int index = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        grid[i][j] = upperTriangle[index++];
      }
    }

    return grid;
  }
};
// wrong
