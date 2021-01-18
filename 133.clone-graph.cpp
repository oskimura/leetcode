#include <vector>
#include <queue>
#include <map>

using namespace std;
/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start

// Definition for a Node.
/*
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/
class Solution {
public:
    map<Node*,Node*> copie;

    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }

        Node *copy = new Node(node->val);
        copie[node] = copy;
        
        queue<Node*> q;
        q.push(node);
        while (!q.empty())
        {
            Node* v = q.front();
            q.pop();

            for (size_t i = 0; i < v->neighbors.size(); i++)
            {
                Node* nv = v->neighbors[i];
                if (copie.find(nv) == copie.end()) {
                    q.push(nv);
                    copie[nv] = new Node(nv->val);
                }
                
                copie[v]->neighbors.push_back(copie[nv]);
            } 
        }
        
       return copy;
    }
};
// @lc code=end

