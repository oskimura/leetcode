// @before-stub-for-debug-begin
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {

    queue<string> q;
    q.push(beginWord);
    unordered_set<string> dict(wordList.begin(), wordList.end());

    int cnt = 1;
    while (!q.empty()) {
      int n = q.size();
      for (size_t i = 0; i < n; i++) {
        string s = q.front();
        q.pop();
        if (endWord == s) {
          return cnt;
        }

        string tmp = s;
        dict.erase(s);
        for (size_t j = 0; j < s.size(); j++) {
          for (size_t k = 0; k < 26; k++) {
            tmp[j] = 'a' + k;
            if (dict.find(tmp) != dict.end()) {
              q.push(tmp);
            }
          }
          tmp = s;
        }
      }

      cnt++;
    }
    return 0;
  }
};
// @lc code=end
