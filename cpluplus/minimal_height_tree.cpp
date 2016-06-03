/*
 * author: yuandx
 * create: 2016-06-01
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
#include <deque>
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
  toplogical sort
  first add all the to queue
  for every node in the queue:
    for every adjacent node :
 *      delete from adjacent
        if other node == 1
           add to temp
    return queue;
 */
class Solution
{
public:
  //topological
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges)
  {
    vector<set<int>> v(n, set<int>());
    vector<bool> mark(n, false);
    for (auto it = edges.begin(); it != edges.end(); ++it)
    {
      v[it->first].insert(it->second);
      v[it->second].insert(it->first);
    }
    vector<int> leaf;
    for (auto it = v.begin(); it != v.end(); ++it)
    {
      if (it->size() <= 1u)
      {
        leaf.push_back(it - v.begin());
        mark[it - v.begin()] = true;
      }
    }
    while (true)
    {
      vector<int> temp;
      for (auto it = leaf.begin(); it != leaf.end(); ++it)
      {
        int e1 = *it;
        if (v[e1].size() >= 1)
        {
          int e2 = *(v[e1].begin());
          v[e1].erase(e2);
          v[e2].erase(e1);
          if (v[e2].size() <= 1u && mark[e2] == false)
          {
            temp.push_back(e2);
            mark[e2] = true;
          }
        }
      }
      if (temp.empty())
        return leaf;
      leaf.swap(temp);
    }
  }
};

int main()
{
  int n = 4;
  vector<pair<int, int>> edges= {{1, 0}, {1, 2}, {1, 3}};
  int n2 = 6;
  vector<pair<int, int>> edges2= {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};

  Solution sol;
  vector<int> result = sol.findMinHeightTrees(n2, edges2);
  for (auto it = result.begin(); it != result.end(); ++it)
  {
    cout << *it << endl;
  }

  return 0;
}
