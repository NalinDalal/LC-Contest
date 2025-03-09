/*Q2. Choose K Elements With Maximum Sum
Medium
4 pt.
You are given two integer arrays, nums1 and nums2, both of length n, along with
a positive integer k.

For each index i from 0 to n - 1, perform the following:

Find all indices j where nums1[j] is less than nums1[i].
Choose at most k values of nums2[j] at these indices to maximize the total sum.
Return an array answer of size n, where answer[i] represents the result for the
corresponding index i.



Example 1:

Input: nums1 = [4,2,1,5,3], nums2 = [10,20,30,40,50], k = 2

Output: [80,30,0,80,50]

Explanation:

For i = 0: Select the 2 largest values from nums2 at indices [1, 2, 4] where
nums1[j] < nums1[0], resulting in 50 + 30 = 80. For i = 1: Select the 2 largest
values from nums2 at index [2] where nums1[j] < nums1[1], resulting in 30. For i
= 2: No indices satisfy nums1[j] < nums1[2], resulting in 0. For i = 3: Select
the 2 largest values from nums2 at indices [0, 1, 2, 4] where nums1[j] <
nums1[3], resulting in 50 + 30 = 80. For i = 4: Select the 2 largest values from
nums2 at indices [1, 2] where nums1[j] < nums1[4], resulting in 30 + 20 = 50.
Example 2:

Input: nums1 = [2,2,2,2], nums2 = [3,1,2,3], k = 1

Output: [0,0,0,0]

Explanation:

Since all elements in nums1 are equal, no indices satisfy the condition nums1[j]
< nums1[i] for any i, resulting in 0 for all positions.



Constraints:

n == nums1.length == nums2.length
1 <= n <= 105
1 <= nums1[i], nums2[i] <= 106
1 <= k <= n*/

class Solution {
public:
  vector<long long> findMaxSum(vector<int> &nums1, vector<int> &nums2, int k) {
    int n = (int)nums1.size();
    vector<long long> ans(n, 0);

    vector<array<long long, 3>> arr(n);
    for (int i = 0; i < n; i++) {
      arr[i] = {(long long)nums1[i], (long long)nums2[i], (long long)i};
    }

    sort(arr.begin(), arr.end(), [](auto &a, auto &b) { return a[0] < b[0]; });

    vector<array<long long, 2>> queries(n);
    for (int i = 0; i < n; i++) {
      queries[i] = {(long long)nums1[i], (long long)i};
    }

    sort(queries.begin(), queries.end(),
         [](auto &a, auto &b) { return a[0] < b[0]; });

    multiset<long long> small, large;
    long long sumLarge = 0;

    auto balance = [&](long long val) {
      if ((int)large.size() < k || val >= *large.begin()) {
        large.insert(val);
        sumLarge += val;

        if ((int)large.size() > k) {
          auto it = large.begin();
          sumLarge -= *it;
          small.insert(*it);
          large.erase(it);
        }
      } else {
        small.insert(val);
      }
    };

    int p = 0;
    for (auto &q : queries) {
      long long val = q[0], idx = q[1];
      while (p < n && arr[p][0] < val) {
        balance(arr[p][1]);
        p++;
      }
      ans[idx] = sumLarge;
    }

    return ans;
  }
};
// sub:
// https://leetcode.com/contest/weekly-contest-440/problems/choose-k-elements-with-maximum-sum/submissions/1567657299/?slug=choose-k-elements-with-maximum-sum&region=global_v2
