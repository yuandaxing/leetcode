/*
 * author: yuandx
 * create: 2016-06-03
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
/*
 *
 */
struct Slider
{
  int v;
  int prime;
  int idx;
};

auto compare = [](const Slider& lhs, const Slider& rhs)
{
  return  lhs.v < rhs.v;
};

class Solution
{
public:
  int nthSuperUglyNumber(int n, vector<int>& primes)
  {
    vector<int> result;
    result.push_back(1);
    set<Slider, decltype(compare)> candidate(compare);
    for (auto it = primes.begin(); it != primes.end(); ++it)
    {
      candidate.insert({*it, *it, 0});
    }

    while (static_cast<int>(result.size()) < n)
    {
      auto first = candidate.begin();
      result.push_back(first->v);
      Slider tmp = *first;
      candidate.erase(first);
      do
      {
      tmp.idx++;
      tmp.v = tmp.prime * result[tmp.idx];
      } while (candidate.find(tmp) != candidate.end());
      candidate.insert(tmp);
    }
    return result[n-1];
  }
};

int main()
{
  Solution sol;
  vector<int> v = {2, 7, 13, 19};
  cout << sol.nthSuperUglyNumber(12, v) << endl;
  return 0;
}
