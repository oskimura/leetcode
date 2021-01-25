// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <iosteam>
#include <map>
#include <priority_queue>

using namespace std;
// @before-stub-for-debug-end


/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for (size_t i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        priority_queue< pair<int,int>> q;
        
        for (auto it = m.begin(); it != m.end(); it++) {
            q.push(make_pair(it->second,it->first));
        }
        vector<int> v;
        for (size_t i = 0; i < k; i++)
        {
            v.push_back(q.top().second);
             q.pop();
        }
        return v;
    }
};
// @lc code=end

