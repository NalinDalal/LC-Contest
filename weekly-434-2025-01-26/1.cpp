/* https://leetcode.com/contest/weekly-contest-434/problems/count-partitions-with-even-sum-difference/description/
Q1. Count Partitions with Even Sum Difference
Easy
3 pt.
You are given an integer array nums of length n.

A partition is defined as an index i where 0 <= i < n - 1, splitting the array
into two non-empty subarrays such that:

Left subarray contains indices [0, i].
Right subarray contains indices [i + 1, n - 1].
Return the number of partitions where the difference between the sum of the left
and right subarrays is even.



Example 1:
Input: nums = [10,10,3,7,6]
Output: 4
Explanation:
The 4 partitions are:
[10], [10, 3, 7, 6] with a sum difference of 10 - 26 = -16, which is even.
[10, 10], [3, 7, 6] with a sum difference of 20 - 16 = 4, which is even.
[10, 10, 3], [7, 6] with a sum difference of 23 - 13 = 10, which is even.
[10, 10, 3, 7], [6] with a sum difference of 30 - 6 = 24, which is even.

Example 2:
Input: nums = [1,2,2]
Output: 0
Explanation:No partition results in an even sum difference.

Example 3:
Input: nums = [2,4,6,8]
Output: 3
Explanation:All partitions result in an even sum difference.



Constraints:
2 <= n == nums.length <= 100
1 <= nums[i] <= 100
*/

#include <cmath>
#include <vector>

using namespace std;

// 0<=i<n-1
//[0,i],[i+1,n-1]
// abs(sum(0,i)-sum(i+1,n-1))%2==0
// then increase count

class Solution {
public:
  int countPartitions(vector<int> &nums) {
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n - 1; i++) {
      int sum_left = 0;
      int sum_right = 0;

      // Calculate sum of elements from nums[0] to nums[i]
      for (int j = 0; j <= i; j++) {
        sum_left += nums[j];
      }

      // Calculate sum of elements from nums[i+1] to nums[n-1]
      for (int j = i + 1; j < n; j++) {
        sum_right += nums[j];
      }

      // Check if the absolute difference between sums is even
      if (abs(sum_left - sum_right) % 2 == 0) {
        count++;
      }
    }

    return count;
  }
};

// sub:
// https://leetcode.com/contest/weekly-contest-434/problems/count-partitions-with-even-sum-difference/submissions/1520587538/
