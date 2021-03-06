#include <iostream>
#include <vector>
using namespace  std;

/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        unsigned int res = 0;
        while (x != 0)
        {
            res = res*10 + x%10;
            x /= 10;
        }
        
        return (res > INT_MAX || res < INT_MIN)? 0 : res;
    }
};
// @lc code=end

