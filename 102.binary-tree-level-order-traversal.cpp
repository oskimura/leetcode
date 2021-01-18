/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
  vector<vector<int>> v;

public:
  void levelOrder_(TreeNode *root, int level) {
    if (root == NULL) {
      return;
    } else {
      if (level >= v.size()) {
        v.push_back(vector<int>());
      }
      v[level].push_back(root->val);
      levelOrder_(root->left, level + 1);
      levelOrder_(root->right, level + 1);
    }
  }
  vector<vector<int>> levelOrder(TreeNode *root) {
    levelOrder_(root, 0);
    return v;
  }
};
// @lc code=end
