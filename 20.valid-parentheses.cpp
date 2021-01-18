// @before-stub-for-debug-begin
#include <stack>
#include <string>
#include <vector>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
  bool isValid(string s) {
    stack<char> ss;
    try {
      for (size_t i = 0; i < s.length(); i++) {
        switch (s[i]) {
        case '(':
        case '[':
        case '{':
          ss.push(s[i]);
          break;
        case ')':
          if (!ss.empty() && '(' == ss.top()) {
            ss.pop();
            continue;
          } else {
            return false;
          }
          break;
        case ']':
          if (!ss.empty() && '[' == ss.top()) {
            ss.pop();
            continue;
          } else {
            return false;
          }
          break;
        case '}':
          if (!ss.empty() && '{' == ss.top()) {
            ss.pop();
            continue;
          } else {
            return false;
          }
          break;
        default:
          break;
        }
      }
    } catch (exception e) {
      return false;
    }
    return ss.empty();
  }
};
// @lc code=end
