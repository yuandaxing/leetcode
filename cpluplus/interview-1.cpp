/*
 * author: yuandx
 * create: 2016-05-12
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
  void Solve(vector<int>& v, vector<int>& idx)
  {
    int size = idx.size();
    for(int i = 0; i != size; i++)
    {
      if(idx[i] >= size)
        continue;
      int next = idx[i], cur = i;
      while (next != i)
      {
        std::swap(v[next], v[cur]);
        idx[cur] += size;
        cur = next;
        next = idx[next];
      }
      idx[cur] += size;
    }
    for (auto it = idx.begin(); it != idx.end(); ++it)
    {
      *it -= size;
    }
  }
};

int main()
{
  Solution s;
  vector<int> v1 = {5, 8, 9, 1}, v2 = {1, 3, 2, 0};
  s.Solve(v1, v2);
  for (auto it = v1.begin(); it != v1.end(); ++it)
  {
    cout << *it << " " << endl;
  }
  return 0;
}
