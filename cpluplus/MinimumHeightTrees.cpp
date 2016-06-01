/*
 * author: yuandx
 * create: 2016-05-15
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
 * all pairs shortest path O(n3)
 *  ballman ford algorithm
 * for row in rows
 * for col in cols:
    for k in nodes:
     if F[row, k] [k, col]
        F[row][col] = std::min(F[row][col], F[row][k] + F[k][col])
 *
 *
 *
 */

class Solution
{
public:
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges)
  {
    vector<vector<int>> all_path(n, vector<int>(n, INT_MAX));
    for (auto it = edges.begin(); it != edges.end(); ++it)
    {
      all_path[it->first][it->second] = 1;
      all_path[it->second][it->first] = 1;
    }
    for (int k = 0; k < n; k++)
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          if (all_path[i][k] != INT_MAX && all_path[k][j] != INT_MAX)
          {
            all_path[i][j] = std::min(all_path[i][j], all_path[i][k] + all_path[k][j]);
          }
        }
      }
    }
    vector<int> mins, result;
    int g_min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
      int cur = INT_MIN;
      for (int j = 0; j < n; j++)
      {
        cur = std::max(cur, all_path[i][j]);
      }
      mins.push_back(cur);
      g_min = std::min(cur, g_min);
    }
    for (int i = 0; i < n; i++)
    {
      if (mins[i] == g_min)
      {
        result.push_back(i);
      }
    }
    return result;
  }
};

int main()
{
  int n = 6;
  vector<pair<int, int>> edges= {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
  Solution sol;
  vector<int> result = sol.findMinHeightTrees(n, edges);
  for (auto it = result.begin(); it != result.end(); ++it)
  {
    cout << *it << endl;
  }
  return 0;
}
