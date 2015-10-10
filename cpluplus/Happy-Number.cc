#include <set>
#include <vector>
#include <algorithm>

using std::set;
using std::vector;
class Solution
{
public:
  int NextTry(int i)
  {
    vector<int> tmp;
    for (; i != 0; i = i / 10)
    {
      tmp.push_back(i % 10);
    }
    int next = 0;
    for (vector<int>::iterator it = tmp.begin(); it != tmp.end(); ++it)
    {
      next += (*it) * (*it);
    }
    return next;
  }
  bool isHappy(int n)
  {
    set<int> exits;
    while ( n != 1 && exits.find(n) == exits.end())
    {
      exits.insert(n);
      n = NextTry(n);
    }
    return n == 1;
  }
};
