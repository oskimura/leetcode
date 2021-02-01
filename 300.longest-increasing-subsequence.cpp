// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end


/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
    const int INF = 1e9+1;
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n+1,INF);
        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            auto tmp = lower_bound(dp.begin(),dp.end(),x);
            *tmp = x;
        }        
        return (lower_bound(dp.begin(),dp.end(),INF) - dp.begin());
    }
};
// @lc code=end

