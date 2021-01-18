// @before-stub-for-debug-begin
#include <stack>
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
  unsigned long long calc(ListNode *l1) {
    stack<unsigned long long> s;
    while (l1) {
      s.push(l1->val);
      l1 = l1->next;
    }
    unsigned long long n = 0;
    while (!s.empty()) {
      n = n * 10 + s.top();
      s.pop();
    }
    return n;
  }

  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    unsigned long long n = calc(l1) + calc(l2);

    ListNode *p = NULL;
    stack<unsigned long long> s;
    while (n) {
      s.push(n % 10);
      n = n / 10;
    }
    while (!s.empty()) {
      p = new ListNode(s.top(), p);
      s.pop();
    }

    return p?p:new ListNode(0,NULL);
  }
};
// @lc code=end
