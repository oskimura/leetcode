// @before-stub-for-debug-begin
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n + 1, 0);

    for (int i = 0; i < n; i++) {
      dp[i + 1] = max(dp[i] + nums[i], nums[i]);
    }

    int res = nums[0];
    for (int i = 1; i <= n; i++) {
      res = max(res, dp[i]);
    }
    return res;
  }
};
// @lc code=end
