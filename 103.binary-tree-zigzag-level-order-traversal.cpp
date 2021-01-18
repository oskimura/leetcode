#include<algorithm>
/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
public:
    vector<vector<int>> v;

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

  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
      levelOrder_(root,0);
      for (size_t i = 0; i < v.size(); i++)
      {
          if (i%2==1) {
              reverse(v[i].begin(),v[i].end());
          }
      }
      return v;
  }
};
// @lc code=end
