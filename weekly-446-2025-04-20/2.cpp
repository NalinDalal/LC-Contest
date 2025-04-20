/*Q2. Make Array Non-decreasing
Medium
4 pt.
You are given an integer array nums. In one operation, you can select a subarray
and replace it with a single element equal to its maximum value.

Return the maximum possible size of the array after performing zero or more
operations such that the resulting array is non-decreasing.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [4,2,5,3,5]
Output: 3
Explanation:
One way to achieve the maximum size is:

Replace subarray nums[1..2] = [2, 5] with 5 → [4, 5, 3, 5].
Replace subarray nums[2..3] = [3, 5] with 5 → [4, 5, 5].
The final array [4, 5, 5] is non-decreasing with size 3.

Example 2:
Input: nums = [1,2,3]
Output: 3
Explanation:No operation is needed as the array [1,2,3] is already
non-decreasing.



Constraints:
1 <= nums.length <= 2 * 105
1 <= nums[i] <= 2 * 105
*/
/*We want to make the array non-decreasing, using operations that reduce
subarrays to their max. Our goal is to perform minimal merges, preserving as
many values as possible.

So the key idea is:

Traverse from left to right, and whenever nums[i] < nums[i-1], it means we must
merge the previous segment to fix the order — and continue merging backward if
needed.
 */

class Solution {
public:
  int maximumPossibleSize(vector<int> &nums) {
    int n = nums.size(), l = 0, r, res = 0, m;

    while (l < n) {
      m = nums[l];
      r = l + 1;

      while (r < n && nums[r] < m) {
        if (nums[r] > m)
          m = nums[r];
        r++;
      }

      res++;
      l = r;
    }

    return res;
  }
};
// sub:
// https://leetcode.com/contest/weekly-contest-446/problems/make-array-non-decreasing/submissions/1612045477/
