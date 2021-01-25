// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem153.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int m = l + (r - l) / 2;

        while (l<=r) {
            m = l + (r - l) / 2;
            cout << l << " " << m << " " << r << endl;
            if (nums[l]<=nums[r]) {
                break;
            } else if (nums[l]>nums[m]) {
                r = m;
            } else {
                l = m+1;
            }
        }
        return nums[l];
    }
};
// @lc code=end

