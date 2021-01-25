// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <priority_queue>
#include <map>
#include <iostream>

using namespace std;
// @before-stub-for-debug-end



/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue<pair<int, vector<int> > > q;
        for (size_t i = 0; i < nums1.size(); i++)
        {
            for (size_t j = 0; j < nums2.size(); j++)
            {
                vector<int> tmp;
                tmp.push_back(nums1[i]);
                tmp.push_back(nums2[j]);
                q.push({nums1[i]+nums2[j], tmp});
                
                if (q.size()>k) {
                    q.pop();                
                }
            }
        }
        
        vector<vector<int> > res;
        while(!q.empty())
        {
            auto x = q.top();
            vector<int> tmp;
  
            res.push_back(x.second);
            q.pop();
        }
        return res;     
    }
};
// @lc code=end

