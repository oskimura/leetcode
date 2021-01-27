// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem22.h"

using namespace std;
// @before-stub-for-debug-end

using namespace std;
// @before-stub-for-debug-end
#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>
/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> ans;
    int N;

/*
    void generateParenthesis_(string s, int n) {
        cout << s << endl;
        if (n==0) {
            ans.push_back(s);
            return ;
        }


        for (size_t i = n; i < N; i++) {

            s.push_back('(');
            generateParenthesis_(s,n-1);
            s.push_back(')');
        }

    
    }
*/

    void gen(int open, int close, string str) {
        cout << str << endl;
        if (open == N && close == N) {
            ans.push_back(str);
            return;
        }
        else {
            if (open < N) {
                str+='(';
                gen(open+1,close,str);
                str.pop_back();
            }
            if (close < open) {
                str+=')';
                gen(open,close+1,str);
                str.pop_back();
            }
        }
    }

    vector<string> generateParenthesis(int n) {
       this->N = n;
       gen(0,0,"");

       return ans;
    }
};
// @lc code=end

