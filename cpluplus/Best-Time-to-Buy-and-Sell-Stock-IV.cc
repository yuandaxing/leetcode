#include <vector>
#include <iostream>

using std::vector;
using std::cout;

class Solution
{
public:

  /*
   * dp
   * F[i][k] = max{ f[j][k-1] + max(j+1, i) - min(j+1, i) }
   * tight form max {f[j][k-1]+ max(j+1, i) - A[j+1]}
   */
  int maxProfit(int k, vector<int>& prices)
  {
    if (prices.size() == 0) return 0;
    vector<vector<int> > F;
    F.push_back(vector<int>(prices.size(), 0));
    F.push_back(vector<int>(prices.size(), 0));
    for (int k1 = 1; k1 <= k; k1++)
    {
      for (int i = 0; i < prices.size(); i++)
      {
        int maxV = prices[i];
        for (int j = i-1; j >= -1; j--)
        {
          maxV = std::max(maxV, prices[j+1]);
          F[1][i] = std::max((j == -1 ? 0 : F[1-1][j]) + maxV - prices[j+1], F[1][i]);
        }
      }
      F[1].swap(F[0]);
      std::fill(F[1].begin(), F[1].end(), 0);
    }
    return F[0][prices.size()-1];
  }
};

int main(int argc, char *argv[])
{
  int a[] = {2,1,2,0,1};
  vector<int> t(a, a+5);


  Solution sol;
  cout << sol.maxProfit(2, t) << std::endl;
  return 0;
}
