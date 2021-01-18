#include <iostream>
/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
  double myPow(double x, int n) {
/*
      double tmp = n < 0 ? (1 / x) : x;

    cout << x << endl;
      if (n==0) {
          return 1;
      } else if (n%2==0) {
          if (n>0) {
              return myPow(x*x,n/2);
          } else {
              cout << '-' << endl;
              return myPow(1/(x*x),n/2);
          }
      } else {
          if (n>0) {
              return x * myPow(x*x,(n-1)/2);
          } else {
              cout << '+' << endl;
              return (1/x) * myPow(x*x,(n+1)/2);
          }
      }
*/

    if (n==0){
        return 1;
    }
    double k = 1;
    while (abs((long)n)>1)
    {
        if (n%2!=0) {
            k = n>0? k*x : k/x;
        }
        x*=x;
        n /= 2;
    }
    return n>0? k*x : k/x;
    
    

    /*
    double res = 1;
    while (n) {
      if (n > 0) {
        

          n = n /2;
          res = x*x;


        n--;
        res *= x;
      } else if (n < 0) {
        n++;
        res /= x;
      }
    }
    return res;
    */

  }

};
// @lc code=end
