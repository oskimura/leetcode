/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int max_ = 0;
    for (unsigned int i = 0; i < n-1; i++) {
      max_ += max(0, prices[i + 1] - prices[i]);
    }
    return max_;
  }
};
// @lc code=end
