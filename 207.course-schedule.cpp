// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include<queue>
using namespace std;
#define INPUT "test_case.txt" // single-input
#define OUTPUT cout, "output.txt" // multi-output
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */
// @lc code=start
class Solution {
public:
    vector< vector <int> > G;
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        
        vector< vector<int> > G(numCourses,vector<int>());
        vector<int> indegree(numCourses,0);
        for (size_t i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            G[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        for (size_t i = 0; i < numCourses; i++ )
        {
            if (indegree[i]==0) {
                q.push(i);
            }
        }
        vector<int> sorted;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (size_t i = 0; i < G[u].size(); i++)
            {
                int v = G[u][i];
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
            sorted.push_back(u);    
        }

        
        if (sorted.size() == numCourses) {
            return true;
        } 
        return false;
    }
};
// @lc code=end

