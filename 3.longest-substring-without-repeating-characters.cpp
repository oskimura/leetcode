// @before-stub-for-debug-begin
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int i, j, n;
    i = j = 0;
    n = s.length();
    int max_ = 0;
    int size = 0;
          set<char> window;

    while (i < n && j < n) {
        cout << max_ << endl;

      char c = s[j];
      cout << c << endl;
      if (window.find(c) != window.end()) {
        window.erase(s[i]);
        i++;
      } else {
        cout << "aaa" << endl;
        window.insert(c);
        max_ = max(max_, (int)window.size());
        cout << window.size() << endl;
        j++;
      }
    }
    return max_;
  }
};
// @lc code=end
