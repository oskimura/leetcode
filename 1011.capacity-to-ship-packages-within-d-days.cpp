// @before-stub-for-debug-begin
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution {
public:
  int shipWithinDays(vector<int> &weights, int D) {
    cout << "aaaaa" << endl;

    long long max_num = accumulate(weights.begin(), weights.end(), 0);
    long long min_num = *max_element(weights.begin(), weights.end());
    long long mid = min_num + (max_num - min_num) / 2;

    while (min_num <= max_num) {

      mid = min_num + (max_num - min_num) / 2;
      long days = 0;
      long w = 0;

      cout << min_num << " " << mid << " " << max_num << endl;
      for (size_t i = 0; i < weights.size(); i++) {
        w += weights[i];

        if (w > mid) {
          days++;
          w = weights[i];
        }
        // cout << w << "  " << days << endl;
      }

      if (days >= D) {
        min_num = mid + 1;

      } else {
        max_num = mid - 1;
      }
    }

    return min_num;
  }
};
// @lc code=end
