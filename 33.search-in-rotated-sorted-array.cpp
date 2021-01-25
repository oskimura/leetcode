// @before-stub-for-debug-begin
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    int m = l + (r - l) / 2;
    while (l <= r) {
      m = l + (r - l) / 2;
      cout << l << " " << m << " " << r << endl;
      if (nums[l] <= nums[r]) {
        break;
      } else if (nums[l] > nums[m]) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    cout << l << endl;

    int n = nums.size() - l;
    cout << n << endl;

    map<int, int> ma;
    for (size_t i = 0; i < nums.size(); i++) {
      if (i < n) {
        // ma[i + l] = i ;
        ma[i] = i + l;
        cout << i + l << " " << i << endl;
      } else {
        ma[i] = i - n;
        cout << i - n << " " << i << endl;
      }
    }

    l = 0;
    r = nums.size() - 1;
    m = l + (r - l) / 2;
    while (l <= r) {
      m = l + (r - l) / 2;
      if (nums[ma[m]] == target) {
        return ma[m];
      } else if (target > nums[ma[m]]) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    return -1;
  }
};
// @lc code=end
