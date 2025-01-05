/* Q1. Maximum Subarray With Equal Products
Easy
3 pt.
You are given an array of positive integers nums.

An array arr is called product equivalent if prod(arr) == lcm(arr) * gcd(arr),
where:

prod(arr) is the product of all elements of arr.
gcd(arr) is the GCD of all elements of arr.
lcm(arr) is the LCM of all elements of arr.
Return the length of the longest product equivalent subarray of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

The term gcd(a, b) denotes the greatest common divisor of a and b.

The term lcm(a, b) denotes the least common multiple of a and b.



Example 1:

Input: nums = [1,2,1,2,1,1,1]

Output: 5

Explanation:

The longest product equivalent subarray is [1, 2, 1, 1, 1], where prod([1, 2, 1,
1, 1]) = 2, gcd([1, 2, 1, 1, 1]) = 1, and lcm([1, 2, 1, 1, 1]) = 2.

Example 2:

Input: nums = [2,3,4,5,6]

Output: 3

Explanation:

The longest product equivalent subarray is [3, 4, 5].

Example 3:

Input: nums = [1,2,3,1,4,5,1]

Output: 5



Constraints:

2 <= nums.length <= 100
1 <= nums[i] <= 10*/

#include <numeric> // For gcd
#include <vector>
using namespace std;

class Solution {
public:
  int maxLength(vector<int> &nums) {
    int n = nums.size();
    int maxLen = 0;

    // Iterate over all starting points
    for (int i = 0; i < n; ++i) {
      long long prod = 1;
      int gcd_so_far = nums[i];

      for (int j = i; j < n; ++j) {
        // Update product and GCD for the current subarray
        prod *= nums[j];
        gcd_so_far = gcd(gcd_so_far, nums[j]);

        // Calculate LCM
        long long lcm = prod / gcd_so_far;

        // Check if the subarray satisfies the condition
        if (prod == lcm * gcd_so_far) {
          maxLen = max(maxLen, j - i + 1);
        }
      }
    }

    return maxLen;
  }
};
