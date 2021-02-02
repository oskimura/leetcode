// @before-stub-for-debug-begin
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {

        if (obstacleGrid[i][j] == 0) {
          if (i == 0 && j == 0) {
            dp[0][0] = 1;
            continue;
          }
          unsigned int l =
              (j > 0) ? (obstacleGrid[i][j - 1] ? 0 : dp[i][j - 1]) : 0;
          unsigned int r =
              (i > 0) ? (obstacleGrid[i - 1][j] ? 0 : dp[i - 1][j]) : 0;
          dp[i][j] = l + r;
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};
// @lc code=end
