#include <vector>
using std::vector;

/*
 * (k - i) * start  > n - cur, return
 * result.size() == k and n - cur == 0 push_back(result)
 */
class Solution {
public:
  void combinationAux(vector<int>& cur, int i, int k, int left, vector<vector<int> >& result)
  {
    if (cur.size() >= k)
    {
      if (cur.size() == k && left == 0)
      {
        result.push_back(cur);
      }
      return ;
    }
    if ((k - cur.size()) * i > left || i > 9)
    {
      return ;
    }
    combinationAux(cur, i+1, k, left, result);
    cur.push_back(i);
    combinationAux(cur, i+1, k, left - i, result);
    cur.pop_back();
  }
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int> > result;
    vector<int> cur;
    combinationAux(cur, 1, k, n, result);
    return result;
  }
};
