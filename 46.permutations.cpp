/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> permute_(vector<int> &nums, int index) {
    vector<vector<int>> ret;
    if (nums.size() <= index) {
      return {nums};
    }
    for (size_t i = index; i < nums.size(); i++) {
      swap(nums[index], nums[i]);
      auto v = permute_(nums, index + 1);
      copy(v.begin(), v.end(), back_inserter(ret));
      swap(nums[index], nums[i]);
    }
    return ret;
  }

  vector<vector<int>> permute(vector<int> &nums) {
        return permute_(nums,0);
  }
};
// @lc code=end
