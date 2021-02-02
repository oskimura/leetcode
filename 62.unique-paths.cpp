// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end


/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<unsigned int>> dp(m+1,vector<unsigned int>(n+1,0));

        /*
        for (size_t i = 0; i <= m; i++)
        {
            dp[i][0] = 1;
        }
        for (size_t i = 0; i <= n; i++)
        {
            dp[0][i] = 1;
        }
        */
        
       dp[0][0] = 1;

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i==0&&j==0) {
                     dp[0][0] = 1;
                     continue;
                }
                unsigned int l = (j>0)?dp[i][j-1]:0;
                unsigned int r = (i>0)?dp[i-1][j]:0;

                dp[i][j] = l+r;
            }
            
        }
        
        
        return dp[m-1][n-1];

    }
};
// @lc code=end

