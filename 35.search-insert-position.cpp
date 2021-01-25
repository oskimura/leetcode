#include <math.h>
/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size()-1;
    int mid = l+(r-l) / 2;
    while (l <= r) {
      mid = l+(r-l) / 2;
      if (target <= nums[mid]) {
        r = mid-1;
      } else {
        l = mid+1;
      }
    }

    return l;
  }
};
// @lc code=end
