/*Q2. Closest Equal Element Queries
Medium
4 pt.
You are given a circular array nums and an array queries.

For each query i, you have to find the following:

The minimum distance between the element at index queries[i] and any other index
j in the circular array, where nums[j] == nums[queries[i]]. If no such index
exists, the answer for that query should be -1. Return an array answer of the
same size as queries, where answer[i] represents the result for query i.



Example 1:

Input: nums = [1,3,1,4,1,3,2], queries = [0,3,5]

Output: [2,-1,3]

Explanation:

Query 0: The element at queries[0] = 0 is nums[0] = 1. The nearest index with
the same value is 2, and the distance between them is 2. Query 1: The element at
queries[1] = 3 is nums[3] = 4. No other index contains 4, so the result is -1.
Query 2: The element at queries[2] = 5 is nums[5] = 3. The nearest index with
the same value is 1, and the distance between them is 3 (following the circular
path: 5 -> 6 -> 0 -> 1). Example 2:

Input: nums = [1,2,3,4], queries = [0,1,2,3]

Output: [-1,-1,-1,-1]

Explanation:

Each value in nums is unique, so no index shares the same value as the queried
element. This results in -1 for all queries.



Constraints:

1 <= queries.length <= nums.length <= 105
1 <= nums[i] <= 106
0 <= queries[i] < nums.length */
#include <algorithm>
#include <unordered_map>
#include <vector>
using std::vector, std::unordered_map, std::min;
class Solution {
public:
  vector<int> solveQueries(vector<int> &nums, vector<int> &queries) {
    int n = nums.size();
    std::unordered_map<int, vector<int>> positions;

    for (int i = 0; i < n; i++)
      positions[nums[i]].push_back(i);

    for (auto &entry : positions) {
      sort(entry.second.begin(), entry.second.end());
    }

    vector<int> ans;
    ans.reserve(queries.size());

    for (int q : queries) {
      int val = nums[q];
      auto &idxList = positions[val];

      if (idxList.size() < 2) {
        ans.push_back(-1);
        continue;
      }

      auto it = lower_bound(idxList.begin(), idxList.end(), q);
      int pos = it - idxList.begin();

      int leftIndex = (pos - 1 + idxList.size()) % idxList.size();
      int rightIndex = (pos + 1) % idxList.size();

      int leftCandidate = idxList[leftIndex];
      int rightCandidate = idxList[rightIndex];

      int distLeft = abs(q - leftCandidate);
      distLeft = min(distLeft, n - distLeft);

      int distRight = abs(q - rightCandidate);
      distRight = min(distRight, n - distRight);

      ans.push_back(min(distLeft, distRight));
    }

    return ans;
  }
};
// sub:
// https://leetcode.com/contest/weekly-contest-441/problems/closest-equal-element-queries/submissions/1575196461/?slug=closest-equal-element-queries&region=global_v2
