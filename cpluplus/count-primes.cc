#include <bitset>
#include <iostream>
#include <algorithm>
using std::cout;
using std::bitset;

class Solution
{
public:
  int countPrimes(int n)
  {
    bool* mark = new bool[n];
    std::fill_n(mark, n+1, false);
    int count = 0;
    for (int i = 2; i < n ;i++)
    {
      if (mark[i] == false)
      {
        count += 1;
        long z = 2;
        while (z*i < n)
        {
          mark[z*i] = true;
          z += 1;
        }
      }
    }
    return count;
  }
};
int main(int argc, char *argv[])
{
  Solution sol;
  cout << sol.countPrimes(10) << std::endl;
  return 0;
}
