// @before-stub-for-debug-begin
#include <string>
#include <vector>
#include <iostream>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {

  int travarse(int x, int y, int n, vector<vector<int>> &G) {
      cout << n << endl;
      cout << x << y << endl;
    if (x < 0 || y < 0 || G.size() <= x || G[0].size() <= y) {
      return n;
    }
    if (G[x][y] == 0) {
      return n;
    }
    G[x][y] = 0;
    return travarse(x + 1, y, n, G)
    + travarse(x - 1, y, n, G) 
    + travarse(x, y + 1, n, G) 
    + travarse(x, y - 1, n, G)
    + 1;
  }

public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int max_ = 0;
    for (size_t i = 0; i < grid.size(); i++) {
      for (size_t j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == 0) {
          continue;
        }
        max_ = max(max_, travarse(i, j, 0, grid));
        cout << " " << endl;
      }
    }
    return max_;
  }
};
// @lc code=end
