// @before-stub-for-debug-begin
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {

public:
  int coinChange(vector<int> &coins, int amount) {
    const int INF = 1L << 29;
    vector<vector<long long>> dp(coins.size() + 1,
                                 vector<long long>(amount + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < coins.size(); i++) {
      for (int j = 0; j <= amount; j++) {
        if (j - coins[i] >= 0) {
          dp[i + 1][j] = min(dp[i][j], dp[i + 1][j - coins[i]] + 1);
        } else {
          dp[i + 1][j] = dp[i][j];
        }
      }
    }
    long long res = dp[coins.size()][amount];
    return res == INF ? -1 : res;
  }
};
// @lc code=end
