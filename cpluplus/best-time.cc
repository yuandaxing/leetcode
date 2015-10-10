#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using std::fill_n;
using std::vector;
using std::cout;
//using std::INT_MIN;

int maxProfit(int k, vector<int>& prices) {
  int n = (int)prices.size();
  if (n <= 1) return 0;
  int fm = 0, km = 0;
  for (int j = 1; j < n; j++) {
    int f = prices[j]-prices[j-1];
    if (f>0) {
      fm += f;
      km++;
    }
  }
  if (k >= km) {
    return fm;
  } else
  {
    int f[n], prev;
    fill_n(f, n, 0);
    for (int i = 1; i <= k; i++) {
      int S = INT_MIN;
      prev = f[0];
      for (int j = 1; j < n; j++) {
        S = std::max(S, prev-prices[j-1]);
        prev = f[j];
        f[j] = std::max(f[j-1], S+prices[j]);
      }
    }
    return f[n-1];
  }
}

int main(int argc, char *argv[])
{
  int a[] = {2, 1, 5, 4};
  vector<int> prices(a, a+4);
  cout << maxProfit(2, prices);
  cout << std::endl;
  return 0;
}
