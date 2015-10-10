#include <string>
#include <algorithm>
using std::string;

class Solution {
public:
  string convertToTitle(int n)
  {
    string ret;
    do
    {
      ret.push_back('A' + (n-1) % 26);
      n = n / 26;
    } while (n != 0) ;
    std::reverse(ret.begin(), ret.end());
    return ret;
  }
};
