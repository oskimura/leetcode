// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <set>

using namespace std;
// @before-stub-for-debug-end


/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> s;
        while (head)
        {
            s.insert(head);
            head = head->next;
            if (s.find(head) != s.end()) {
                return true;
            }
        }
        return false;      
    }
};
// @lc code=end

