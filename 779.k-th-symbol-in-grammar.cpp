// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include <map>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=779 lang=cpp
 *
 * [779] K-th Symbol in Grammar
 */

// @lc code=start
class Solution {
public:
 //map<pair<int,int>,int> m;
    int dp[30][2^30];
    
  vector<int> gen(int n) {
    vector<int> res;
    if (n == 0) {
      res.push_back(0);
      return res;
    } else {
      auto v = gen(n - 1);
      for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == 0) {
          res.push_back(0);
          res.push_back(1);
        } else {
          res.push_back(1);
          res.push_back(0);
        }
      }
      return res;
    }
  }
  
  int kthGrammar(int N, int K) {
      if (K==1) {
          return 0;
      }
      else if (K==2) {
          return 1;
      } else if (K%2==0) {
          return 1^kthGrammar(N-1,K/2);
      } else {
          return kthGrammar(N-1,(K+1)/2);
      }
  }
  
};
// @lc code=end
