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
class Solution
{
public:
  bool BFS(vector<vector<int>>& edges, int start, int& result, int min_path)
  {
    vector<int> path(edges.size(), INT_MAX);
    vector<int> Q;
    Q.push_back(start);
    int length = 0;
    while (!Q.empty())
    {
      if (length > min_path)
        return false;
      vector<int> tmp;
      for (auto it = Q.begin(); it != Q.end(); ++it)
      {
        if (path[*it] != INT_MAX)
          continue;
        path[*it] = length;
        for (auto it1 = edges[*it].begin(); it1 != edges[*it].end(); ++it1)
        {
          if (path[*it1] == INT_MAX)
          {
            tmp.push_back(*it1);
          }
        }
      }
      length++;
      Q.swap(tmp);
    }
    result = length - 1;
    return true;
  }
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges)
  {
    vector<vector<int>> v(n, vector<int>());
    for (auto it = edges.begin(); it != edges.end(); ++it)
    {
      v[it->first].push_back(it->second);
      v[it->second].push_back(it->first);
    }
    vector<int> result;
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
      int cur;
      if (BFS(v, i, cur, min))
      {
        if (cur == min)
        {
          result.push_back(i);
        }
        else
        {
          min = cur;
          result.clear();
          result.push_back(i);
        }
      }
    }
    return result;
  }
};

int main()
{
  int n = 4;
  vector<pair<int, int>> edges= {{1, 0}, {1, 2}, {1, 3}};
  int n2 = 6;
  vector<pair<int, int>> edges2= {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};

  Solution sol;
  vector<int> result = sol.findMinHeightTrees(n, edges);
  for (auto it = result.begin(); it != result.end(); ++it)
  {
    cout << *it << endl;
  }

  return 0;
}
