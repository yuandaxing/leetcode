/*
 * author: yuandx
 * create: 2015-10-31
 * email: yuandx@mvad.com
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <string>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using std::unordered_map;
using std::unordered_set;
using std::ostringstream;
using std::istringstream;
using std::stringstream;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::map;
using std::set;
using std::pair;
using std::sort;
using std::string;
using std::for_each;
class Solution
{
public:
  string getHint(string secret, string guess)
  {
    int A = 0, B = 0;
    for (size_t i = 0; i != secret.size(); i++)
    {
      if (secret[i] == guess[i])
      {
        A++;
      }
      else
      {
        B++;
      }
    }
    ostringstream os;
    os << A << "A" << B << "B";
    return os.str();
  }
};

int main()
{

  return 0;
}
