#include <iostream>
#include <vector>
using std::vector;
/*
 * 5: 101 6:110 7:111
 * 1, 3, 5, 7, 9 &1
 * 2, 3, 6, 7, 10, 11 &2
 * 4, 5, 6, 7,
 */
using std::cout;
class Solution
{
public:
  vector<int> occur(long N)
  {
    vector<int> ret;
    long K = 1;
    while (K <= N)
    {
      int result = (N / 2 / K) * K;
      if ((N & K) == K)
      {
        result += N % K + 1;
      }
      K <<= 1;
      ret.push_back(result);
    }
    return ret;
  }
  long lessfull1(long N)
  {
    long K = 1, ret = 0;
    while ( K <= N)
    {
      ret |= K;
      K <<= 1;
    }
    return ret;
  }
  long rangeAux(long m, long n)
  {
    long K = 1, ret = 0;
    while (K <= n)
    {
      if ((K & n) == K)
      {
        if (n - n % K -1 < m)
        {
          ret |= K;
        }
      }
      K <<= 1;
    }
    return ret;
  }
  int rangeBitwiseAnd(int m, int n)
  {
    return rangeAux(m, n);
  }
};
void print(vector<int> v)
{
  for (int i = 0; i != v.size(); i++)
  {
    cout << v[i] << "\t";
  }
  cout << std::endl;
}
int main(int argc, char *argv[])
{
  Solution sol;
  print(sol.occur(5));
  print(sol.occur(7));
  cout << sol.rangeBitwiseAnd(5, 7) << std::endl;
  cout << sol.rangeBitwiseAnd(2147483646, 2147483647) << std::endl;
  return 0;
}
