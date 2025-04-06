/* Q1. Minimum Pair Removal to Sort Array I
Easy
3 pt.
Given an array nums, you can perform the following operation any number of
times:

Select the adjacent pair with the minimum sum in nums. If multiple such pairs
exist, choose the leftmost one. Replace the pair with their sum. Return the
minimum number of operations needed to make the array non-decreasing.

An array is said to be non-decreasing if each element is greater than or equal
to its previous element (if it exists).



Example 1:
Input: nums = [5,2,3,1]
Output: 2
Explanation:
The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
The array nums became non-decreasing in two operations.

Example 2:
Input: nums = [1,2,2]
Output: 0
Explanation:The array nums is already sorted.



Constraints:
1 <= nums.length <= 50
-1000 <= nums[i] <= 1000*/

// greedily merge adjacent elements that create the most "trouble" for the
// non-decreasing order — specifically, those that violate the condition.

// Approach
/*1. While the array is not non-decreasing, find the adjacent pair with the
smallest sum (choose the leftmost if there are ties).

2. Merge that pair into one element (i.e., replace the two elements with their
sum).

3. Count each such operation.

4. Stop when the array becomes non-decreasing.*/

class Solution {
public:
  bool isNonDecreasing(const std::vector<int> &nums) {
    for (size_t i = 0; i + 1 < nums.size(); ++i) {
      if (nums[i] > nums[i + 1])
        return false;
    }
    return true;
  }
  int minimumPairRemoval(vector<int> &nums) {
    int operations = 0;

    while (!isNonDecreasing(nums)) {
      int minSum = INT_MAX;
      int minIndex = -1;

      // Find the leftmost adjacent pair with the minimum sum
      for (size_t i = 0; i + 1 < nums.size(); ++i) {
        int sum = nums[i] + nums[i + 1];
        if (sum < minSum) {
          minSum = sum;
          minIndex = i;
        }
      }

      // Merge the pair at minIndex
      int merged = nums[minIndex] + nums[minIndex + 1];
      nums.erase(nums.begin() + minIndex, nums.begin() + minIndex + 2);
      nums.insert(nums.begin() + minIndex, merged);
      operations++;
    }

    return operations;
  }
};

// done
