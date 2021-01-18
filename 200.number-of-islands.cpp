// @before-stub-for-debug-begin
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

struct UnionFind {
  vector<int> par;
  UnionFind(int n) : par(n) {
    for (size_t i = 0; i < n; i++) {
      par[i] = i;
    }
  }
  int root(int x) {
    if (par[x] == x) {
      return x;
    } else {
      return par[x] = root(par[x]);
    }
  }
  bool same(int x, int y) {
    int rx = par[x];
    int ry = par[y];
    return rx == ry;
  }
  void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) {
      return;
    } else {
      par[rx] = ry;
    }
  }
};

// @lc code=start
class Solution {

  void traverse(int x, int y, vector<vector<char>> &G) {
    if (x < 0 || y < 0 || G.size() <= x || G[0].size() <= y) {
      return;
    }

    if (G[x][y] == '1') {
      // std::cout << x << ' ' << y << std::endl;
      G[x][y] = '0';
      traverse(x + 1, y, G);
      traverse(x - 1, y, G);
      traverse(x, y + 1, G);
      traverse(x, y - 1, G);
    }
  }

public:
  int numIslands(vector<vector<char>> &grid) {
    int cnt = 0;

    for (size_t i = 0; i < grid.size(); i++) {
      for (size_t j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == '0') {
          continue;
        }
        traverse(i, j, grid);
        cnt++;
      }
    }
    return cnt;
  }
};
// @lc code=end
