/* https://leetcode.com/contest/weekly-contest-433/problems/maximum-and-minimum-sums-of-at-most-size-k-subsequences/description/?slug=sum-of-variable-length-subarrays&region=global_v2

Q2. Maximum and Minimum Sums of at Most Size K Subsequences
Medium
5 pt.
You are given an integer array nums and a positive integer k. Return the sum of
the maximum and minimum elements of all subsequences of nums with at most k
elements.

A non-empty subsequence is an array that can be derived from another array by
deleting some or no elements without changing the order of the remaining
elements.

Since the answer may be very large, return it modulo 109 + 7.


Example 1:

Input: nums = [1,2,3], k = 2

Output: 24

Explanation:

The subsequences of nums with at most 2 elements are:

Subsequence	Minimum	Maximum	Sum
[1]	1	1	2
[2]	2	2	4
[3]	3	3	6
[1, 2]	1	2	3
[1, 3]	1	3	4
[2, 3]	2	3	5
Final Total	 	 	24
The output would be 24.

Example 2:

Input: nums = [5,0,6], k = 1

Output: 22

Explanation:

For subsequences with exactly 1 element, the minimum and maximum values are the
element itself. Therefore, the total is 5 + 5 + 0 + 0 + 6 + 6 = 22.

Example 3:

Input: nums = [1,1,1], k = 2

Output: 12

Explanation:

The subsequences [1, 1] and [1] each appear 3 times. For all of them, the
minimum and maximum are both 1. Thus, the total is 12.



Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
1 <= k <= min(100, nums.length)*/

// traverse subarray of size k like 0 to k-1, then 1 to k, then 2 to k+1 etc
// solve using recursion
// now for this subArray find min and max
// add min and max to total
// return total
/* find every sub array of size 0 to k, then for each subarray find min and max,
subarray sum=min+max{push into a new vector}

return ans=sum(vector)
include subarrays of size 0 to 𝑘 properly
Subarrays should include all possible subarrays of size 1 through 𝑘, as well as
the entire array itself (if 𝑘≥𝑛) note: subsequence not subarray       */

#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
  int minMaxSums(vector<int> &nums, int k) {
    int n = nums.size();
    long long total = 0;

    // Iterate over all possible subsequences using bit masking
    for (int mask = 1; mask < (1L << n); ++mask) {
      vector<int> subseq;

      // Generate the current subsequence based on the mask
      for (int i = 0; i < n; ++i) {
        if (mask & (1L << i)) {
          subseq.push_back(nums[i]);
        }
      }

      // Consider only subsequences of size at most k
      if (subseq.size() <= k) {
        int subMin = *min_element(subseq.begin(), subseq.end());
        int subMax = *max_element(subseq.begin(), subseq.end());
        total += (subMin + subMax);
      }
    }

    return total;
  }
};
/* i think we have hardcoded 1st index, which doesn't satisfy condition

first find all subsequnces
then their sum of 0,last index
return their sum*/
