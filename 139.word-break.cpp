// @before-stub-for-debug-begin
#include <set>
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    int n = s.length();
    int l = wordDict.size();
    set<string> x(wordDict.begin(), wordDict.end());

    vector<bool> dp(n + 1, false);

    dp[0] = true;
    for (int i = 1; i <= n; i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (dp[j]) {
          if (x.count(s.substr(j, i - j)) > 0) {
            dp[i] = true;
            break;
          }
        }
      }
    }
    for (size_t i = 0; i <= n; i++) {
      cout << dp[i] << endl;
    }

    return dp[n];
  }
};
// @lc code=end
