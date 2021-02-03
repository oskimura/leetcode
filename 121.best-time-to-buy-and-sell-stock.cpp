// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end


/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int min_ = 1 << 29;
        int max_ = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            int tmp = prices[i] - min_;
            max_ = max(max_,tmp);
            min_ = min(min_,prices[i]);
        }
        
        return max_;
    }
};
// @lc code=end

