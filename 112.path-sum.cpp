// @before-stub-for-debug-begin
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  bool hasPathSum_(TreeNode *root, int sum) {
    cout << sum << endl;
    if (!root) {
      return false;
    }
    // cout << root->val << endl;

    if (root->left == NULL && root->right == NULL) {
      return sum + root->val == sum_;
    }

    return hasPathSum_(root->left, sum + root->val) ||
           hasPathSum_(root->right, sum + root->val);
  }
  int sum_;

public:
  bool hasPathSum(TreeNode *root, int sum) {
    sum_ = sum;
    if (!root) {
      return false;
    }
    return hasPathSum_(root, 0);
  }
};
// @lc code=end
