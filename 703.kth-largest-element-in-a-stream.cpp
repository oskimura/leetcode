// @before-stub-for-debug-begin
#include <iostream>
#include <priority_queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
class KthLargest {
  int K;
  int sz;
  int v[10000];

public:
  void push(int x) {
    int i = sz;
    while (i > 0) {

      int p = (i - 1) / 2;

      if (v[p] < x) {
        break;
      }

      v[i] = v[p];
      i = p;
    }
    sz++;
    v[i] = x;
  }

  int pop() {
    int result = v[0];
    sz--;
    int x = v[sz];
    int i = 0;
    while (i * 2 + 1 < sz) {
      int a = i * 2 + 1, b = i * 2 + 2;
      if (a < sz && v[b] < v[a]) {
        a = b;
      }
      if (v[a] >= x)
        break;
      v[i] = v[a];
      i = a;
    }
    v[i] = x;

    return result;
  }

  KthLargest(int k, vector<int> &nums) : sz(0), K(k) {
    for (size_t i = 0; i < nums.size(); i++) {
      add(nums[i]);
    }
  }

  int add(int val) {
    push(val);
    cout << endl;

    if (sz > K) {
      int a = pop();
    }
    return v[0];
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
