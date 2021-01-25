// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem78.h"

using namespace std;
// @before-stub-for-debug-end

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        for (size_t bit = 0; bit < (1<<n); bit++)
        {
            vector<int> S;
            for (size_t i = 0; i < n; i++)
            {
                
                if (bit & (1<<i))
                {
                    S.push_back(i);
                }
                
            }
            for (size_t i = 0; i < S.size(); i++)
            {
                cout << S.at(i) << " ";
            }
            cout << endl;

            vector<int> tmp;
            for (size_t i = 0; i < S.size(); i++)
            {     
                    tmp.push_back(nums[S[i]]);
            }
            result.push_back(tmp);
        }
        return result;
    }
};
// @lc code=end

