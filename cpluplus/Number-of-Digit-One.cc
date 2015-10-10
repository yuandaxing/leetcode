#include <iostream>
using std::cout;
using std::endl;

class Solution
{
public:
  /*
   * F[1] = n / 10 + (n % 10) >= 1 ? 1 : 0
   * F[2] = n / 100 * 10 + (n % 100 > 20 ? 10 : < 10 ? 10 : n % 10 + 1)
   */

  int countDigitOne(int n)
  {
    long K = 10;
    long count = 0;
    while (K <= n)
    {
      count += n / K * (K / 10);
      if (n % K >= (K/10 * 2))
      {
        count += K /10;
      } else if (n % K < (K/10))
      {
        count += 0;
      } else
      {
        count += (n % (K / 10) + 1);
      }
      K *= 10;
    }
    return count;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;
  cout << sol.countDigitOne(13) << std::endl;
  return 0;
}
