// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <map>
using namespace std;
// @before-stub-for-debug-end



/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*,int> m;
        int n = 0;
        while (head)
        {
            m.insert(make_pair( head,n));
            n++;
            head = head->next;
            if (m.find(head)!=m.end())
            {
                return head;
            }
            
        }
        return NULL;
    }
};
// @lc code=end

