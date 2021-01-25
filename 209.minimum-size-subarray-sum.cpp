#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
const int INF = 1 << 29;
public:
  int minSubArrayLen(int s, vector<int> &nums) {
    vector<int> v;
    int i, j;
    i = 0;
    j = 1;
    int sum = 0;
    int len = INF;
    if (nums.size()<1) {
        return 0;
    }
    for (size_t left = 0; left < nums.size(); left++) {
      int sum = 0;
      int right = left;
      //cout << len << endl;
      for (; right < nums.size(); right++) {
        
        sum += nums[right];
                 //cout << "left " << left << " right " << right << " sums " << sum << endl;
 
        if (sum  >= s) {
            right;
          break;
        }
      }
      if (sum>=s) {
        len =
            (unsigned long)min((unsigned long)len, (unsigned long)right - left+1);
      }
    }

    return len==INF?0:len;
  }
};
// @lc code=end
