
using namespace std;
// @before-stub-for-debug-end
#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
  int target;
  vector<int> candidates;
  vector<vector<int>> result;
  void combinationSum_(int index, vector<int> v) {

    int sum = accumulate(v.begin(), v.end(), 0);
      cout << sum << endl;
      for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
      }
      cout << endl;


    if (sum == target) {

      result.push_back(v);
      return;
    } else if (sum > target) {
      return;
    } else {
      for (size_t i = index; i < candidates.size(); i++) {
        v.push_back(candidates[i]);
        combinationSum_(i, v);
        v.pop_back();
      }
    }
  }

public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {

    this->target = target;
    this->candidates = candidates;
    vector<int> v;
    combinationSum_(0, v);
    return result;
  }
};
// @lc code=end
