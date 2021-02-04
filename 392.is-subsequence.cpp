// @before-stub-for-debug-begin
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
  bool isSubsequence(string s, string t) {
    int m = s.length();
    int n = t.length();
    if (m == 0 && n == 0) {
      return true;
    }
    if (n == 0) {
      return false;
    }
    if (m == 0) {
      return true;
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
      if (t[i] == s[j]) {

        cout << t[i] << endl;
        if (j == m - 1) {
          return true;
        }
        j++;
      }
    }

    return false;
  }
};
// @lc code=end
