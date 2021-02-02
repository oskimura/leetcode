// @before-stub-for-debug-begin
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
  int rob(vector<int> &nums) {

    int n = nums.size();

    if (n == 0) {
      return -1;
    } else if (n == 1) {
      return nums[0];
    } else if (n == 2) {
      return nums[0] > nums[1] ? nums[0] : nums[1];
    } else if (n == 3) {
      return max(nums[0], max(nums[1], nums[2]));
    }
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
      dp[i + 2] = max(dp[i] + nums[i], dp[i + 1]);
    }
    int m1 = max(dp[n], dp[n - 1]);

    cout << m1 << endl;
    dp[0] = dp[1] = 0;
    for (int i = 1; i < n; i++) {
      dp[i + 1] = max(dp[i - 1] + nums[i], dp[i]);
    }
    int m2 = max(dp[n], dp[n - 1]);

    return max(m1, m2);
  }
};
// @lc code=end
