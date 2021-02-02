// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end


/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(2,0);
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i%2] = dp[i%2] + nums[i];
        }
        
        return max(dp[0],dp[1]);
    }
};
// @lc code=end

