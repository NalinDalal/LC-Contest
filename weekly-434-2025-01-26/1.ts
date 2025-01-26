/* class Solution {
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
};*/

function countPartitions(nums: number[]): number {
  let n = nums.length;
  let count = 0;

  for (let i = 0; i < n - 1; i++) {
    let sum_left = 0;
    let sum_right = 0;

    for (let j = 0; j <= i; j++) {
      sum_left += nums[j];
    }
    for (let j = i + 1; j < n; j++) {
      sum_right += nums[j];
    }
    if (Math.abs(sum_left - sum_right) % 2 == 0) {
      count++;
    }
  }
  return count;
}

//sub: https://leetcode.com/contest/weekly-contest-434/problems/count-partitions-with-even-sum-difference/submissions/1520595640/
