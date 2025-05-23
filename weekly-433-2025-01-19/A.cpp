/* https://leetcode.com/contest/weekly-contest-433/problems/sum-of-variable-length-subarrays/?slug=sum-of-variable-length-subarrays&region=global_v2
*
Q1. Sum of Variable Length Subarrays
Easy
3 pt.
You are given an integer array nums of size n. For each index i where 0 <= i <
n, define a subarray nums[start ... i] where start = max(0, i - nums[i]).

Return the total sum of all elements from the subarray defined for each index in
the array.

A subarray is a contiguous non-empty sequence of elements within an array.


Example 1:

Input: nums = [2,3,1]

Output: 11

Explanation:

i	Subarray	Sum
0	nums[0] = [2]	2
1	nums[0 ... 1] = [2, 3]	5
2	nums[1 ... 2] = [3, 1]	4
Total Sum	 	11
The total sum is 11. Hence, 11 is the output.

Example 2:

Input: nums = [3,1,1,2]

Output: 13

Explanation:

i	Subarray	Sum
0	nums[0] = [3]	3
1	nums[0 ... 1] = [3, 1]	4
2	nums[1 ... 2] = [1, 1]	2
3	nums[1 ... 3] = [1, 1, 2]	4
Total Sum	 	13
The total sum is 13. Hence, 13 is the output.



Constraints:
1 <= n == nums.length <= 100
1 <= nums[i] <= 1000
*/

// Algorithm:
/* Initialize a variable total_sum to 0.
Iterate over the array nums with index 𝑖.
For each 𝑖, compute start = max(0, i - nums[i]).
Compute the sum of the elements in the range [start, i].
Add this sum to total_sum.
Return total_sum.
*/
class Solution {
public:
  int subarraySum(vector<int> &nums) {
    int n = nums.size();
    int total_sum = 0;

    for (int i = 0; i < n; ++i) {
      int start = max(0, i - nums[i]);
      for (int j = start; j <= i; ++j) {
        total_sum += nums[j];
      }
    }

    return total_sum;
  }
};

// Accepted
// sub:
// https://leetcode.com/problems/sum-of-variable-length-subarrays/submissions/1513109063/
// sol:
// https://leetcode.com/problems/sum-of-variable-length-subarrays/solutions/6300918/3427-sum-of-variable-length-subarrays-10-kijs/
