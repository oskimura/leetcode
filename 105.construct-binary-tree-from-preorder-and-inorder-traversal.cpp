// @before-stub-for-debug-begin
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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

  vector<int> preorder_;
  vector<int> inorder_;

  TreeNode *create(int pleft, int pright, int ileft, int iright) {
    cout << pleft << " " << pright << " " << ileft << " " << iright << endl;

    if (pleft > pright || pleft >= preorder_.size() ||
        pright >= preorder_.size()) {
      return NULL;
    }
    int root = preorder_[pleft];
    cout << root << endl;

    auto t = new TreeNode(root);
    size_t i = ileft;
    for (; i < iright; i++) {
      if (inorder_[i] == root) {
        break;
      }
    }
    int len_r = iright - i;
    int len_l = i - ileft;
    cout << len_l << " " << len_r << endl;

    auto result = new TreeNode(root);

    result->left = create(pleft + 1, pleft + len_l, ileft, i-1);

    result->right = create(pleft + len_l + 1, pright, i+1, i + len_r);

    return result;
  }

public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    preorder_ = preorder;
    inorder_ = inorder;
    if (preorder.size() < 1) {
      return NULL;
    }
    int root = preorder_[0];
    return create(0, preorder.size() - 1, 0, preorder.size() - 1);
  }
};
// @lc code=end
