/*
 * author: yuandx
 * create: 2015-10-10
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
  int hIndex(vector<int>& citations)
  {
    sort(citations.begin(), citations.end());
    for (size_t h = citations.size(), i = 0; i != citations.size();
         h--, i++)
    {
      if (citations[i] >= h)
      {
        return h;
      }
    }
    return 0;
  }
};

int main()
{
  Solution sol;
  vector<int> ci = {3, 0, 6, 1, 5};
  cout << sol.hIndex(ci) << endl;
  return 0;
}
