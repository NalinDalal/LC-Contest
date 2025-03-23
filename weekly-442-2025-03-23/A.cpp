/*Q1. Maximum Containers on a Ship
Easy
3 pt.
You are given a positive integer n representing an n x n cargo deck on a ship.
Each cell on the deck can hold one container with a weight of exactly w.
However, the total weight of all containers, if loaded onto the deck, must not
exceed the ship's maximum weight capacity, maxWeight. Return the maximum number
of containers that can be loaded onto the ship.



Example 1:
Input: n = 2, w = 3, maxWeight = 15
Output: 4
Explanation:
The deck has 4 cells, and each container weighs 3. The total weight of loading
all containers is 12, which does not exceed maxWeight.

Example 2:
Input: n = 3, w = 5, maxWeight = 20
Output: 4
Explanation:
The deck has 9 cells, and each container weighs 5. The maximum number of
containers that can be loaded without exceeding maxWeight is 4.



Constraints:
1 <= n <= 1000
1 <= w <= 1000
1 <= maxWeight <= 109
*/

class Solution {
public:
  int maxContainers(int n, int w, int maxWeight) {
    // nxn matrix
    // so totalDeckWt=n*n*w
    // now maxWt>=totalDeckWt{success loading}
    // return maxContainers which can be loaded so that totalDeckWt<=maxWt
    int ans = 0;
    int totalDeckWt = pow(n, 2) * w;
    if (totalDeckWt == maxWeight)
      ans = pow(n, 2);
    else if (totalDeckWt > maxWeight)
      ans = maxWeight / w;
    else
      ans = totalDeckWt / w;
    return ans;
  }
};
// sub:
// https://leetcode.com/contest/weekly-contest-442/problems/maximum-containers-on-a-ship/submissions/1582832298/
