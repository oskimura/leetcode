// @before-stub-for-debug-begin
#include <queue>
#include <string>
#include <vector>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {

      if (!head||!head->next) {
          return head;
      }
      ListNode* p = head->next;
      if (p && head->val != p->val) {
          head->next = deleteDuplicates(p);
          return head;
      }
      else if (p && head->val == p->val) {
          while (p && head->val == p->val) {
              p = p->next;
          }
          return deleteDuplicates(p);
      }
      else {
          return head;
      }
  }
};

// @lc code=end
