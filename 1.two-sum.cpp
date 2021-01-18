#include <vector>
/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto x = vector<int>(2);
        for (size_t i = 0; i < nums.size()-1; i++)
        {
            for (size_t j = i+1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target) {
                    
                    x[0] = i;
                    x[1] = j;
                    return x;
                }
            }
        }
        return x;
    }
};
// @lc code=end


