// @before-stub-for-debug-begin
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
  TreeNode *sortedArrayToBST_(vector<int> &nums, int start, int end) {
    cout << start << " " << end << endl;
    if (end <= start) {
      return NULL;
    }
    int mid = (start + end) / 2;

    TreeNode *root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST_(nums, start, mid);
    root->right = sortedArrayToBST_(nums, mid + 1, end);

    return root;
  }

  TreeNode *insert(TreeNode *t, int val) {
    if (t == NULL) {
      return new TreeNode(val, NULL, NULL);
    }
    if (t->val < val) {
      t->right = insert(t->right, val);
      return t;
    } else {
      t->left = insert(t->left, val);
      return t;
    }
  }

  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return sortedArrayToBST_(nums, 0, nums.size());
  }
};
// @lc code=end
