// @before-stub-for-debug-begin
#include <stack>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
  ListNode *reverseList(ListNode *head) {
    stack<int> ss;



    ListNode *tmp = head;
    while (head) {
      ss.push(head->val);
      head = head->next;
    }
    head = tmp;
    
    while (!ss.empty() && head) {
      head->val = ss.top();
      //cout << head->val << endl;
      ss.pop();
      head = head->next;
    }

    return tmp;
  }
};
// @lc code=end
