/* Q1. Find the Largest Almost Missing Integer

You are given an integer array nums and an integer k.

An integer x is almost missing from nums if x appears in exactly one subarray of
size k within nums.

Return the largest almost missing integer from nums. If no such integer exists,
return -1.

A subarray is a contiguous sequence of elements within an array.


Example 1:

Input: nums = [3,9,2,1,7], k = 3

Output: 7

Explanation:

1 appears in 2 subarrays of size 3: [9, 2, 1] and [2, 1, 7].
2 appears in 3 subarrays of size 3: [3, 9, 2], [9, 2, 1], [2, 1, 7].
3 appears in 1 subarray of size 3: [3, 9, 2].
7 appears in 1 subarray of size 3: [2, 1, 7].
9 appears in 2 subarrays of size 3: [3, 9, 2], and [9, 2, 1].
We return 7 since it is the largest integer that appears in exactly one subarray
of size k.

Example 2:

Input: nums = [3,9,7,2,1,7], k = 4

Output: 3

Explanation:

1 appears in 2 subarrays of size 4: [9, 7, 2, 1], [7, 2, 1, 7].
2 appears in 3 subarrays of size 4: [3, 9, 7, 2], [9, 7, 2, 1], [7, 2, 1, 7].
3 appears in 1 subarray of size 4: [3, 9, 7, 2].
7 appears in 3 subarrays of size 4: [3, 9, 7, 2], [9, 7, 2, 1], [7, 2, 1, 7].
9 appears in 2 subarrays of size 4: [3, 9, 7, 2], [9, 7, 2, 1].
We return 3 since it is the largest and only integer that appears in exactly one
subarray of size k.

Example 3:

Input: nums = [0,0], k = 1

Output: -1

Explanation:

There is no integer that appears in only one subarray of size 1.



Constraints:

1 <= nums.length <= 50
0 <= nums[i] <= 50
1 <= k <= nums.length*/
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  int largestInteger(vector<int> &nums, int k) {
    // find largest almost missing number
    // x must appear exactly once in each subarray of size k
    // Find the maximum integer that can start the subarray starting at index
    // i
    unordered_map<int, int> subarrayCount;
    int n = nums.size();

    // Step 1: Count frequency of each number in subarrays using sliding window
    for (int i = 0; i <= n - k; ++i) {
      unordered_map<int, int> windowFreq;
      for (int j = i; j < i + k; ++j) {
        windowFreq[nums[j]] = 1; // Ensure unique elements in the subarray count
      }
      for (auto &[num, _] : windowFreq) {
        subarrayCount[num]++;
      }
    }

    // Step 2: Find the largest number that appears exactly once
    int maxAlmostMissing = -1;
    for (auto &[num, count] : subarrayCount) {
      if (count == 1) {
        maxAlmostMissing = max(maxAlmostMissing, num);
      }
    }

    return maxAlmostMissing;
  }
};

int main() {
  Solution s;
  vector<int> nums1 = {3, 9, 2, 1, 7};
  int k1 = 3, test1 = 7;
  if (s.largestInteger(nums1, k1) == test1) {
    cout << "Accepted" << endl;
  }
}

// solved
// sub:
// https://leetcode.com/contest/weekly-contest-439/problems/find-the-largest-almost-missing-integer/submissions/1559827872/?slug=longest-palindromic-subsequence-after-at-most-k-operations&region=global_v2
