// @before-stub-for-debug-begin
#include <iostream>
#include <stack.h>
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
  vector<int> v;
  void isValidBST_(TreeNode *root) {
    if (!root) {
      return;
    }
    if (root->left) {
      isValidBST_(root->left);
    }
    //cout << s.top() << endl;

    v.push_back(root->val);
    cout << root->val << endl;

    if (root->right) {
      isValidBST_(root->right);
    }
    //cout << s.top() << endl;
  }

  bool isValidBST(TreeNode *root) {

    isValidBST_(root);
    if (v.size() < 2) {
      return true;
    }
    for (size_t i = 0; i < v.size() - 1; i++) {
      if (v[i] >= v[i + 1]) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
