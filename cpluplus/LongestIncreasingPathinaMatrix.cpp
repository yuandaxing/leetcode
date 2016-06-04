/*
 * author: yuandx
 * create: 2016-06-04
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
  int longestIncreasingPath(vector<vector<int>>& matrix)
  {
    if (matrix.size() == 0 || matrix[0].size() == 0)
      return 0;
    int row = static_cast<int>(matrix.size()), col = static_cast<int>(matrix[0].size());
    int g_max = INT_MIN;
    vector<vector<int>> path(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
      {
        int left = (j-1 >= 0) ? matrix[i][j-1] : INT_MAX,
          up = (i-1 >= 0) ? matrix[i-1][j] : INT_MAX;
        int max_v = 1;
        max_v = std::max(max_v, (matrix[i][j] > left ? path[i][j-1] : 0) + 1);
        max_v = std::max(max_v, (matrix[i][j] > up ? path[i-1][j] : 0) + 1);
        path[i][j] = max_v;
        g_max = std::max(g_max, max_v);
      }
    }
    vector<vector<int>> path1(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
      {
        int left = (j-1 >= 0) ? matrix[i][j-1] : INT_MIN,
          up = (i-1 >= 0) ? matrix[i-1][j] : INT_MIN;
        int max_v = 1;
        max_v = std::max(max_v, (matrix[i][j] < left ? path1[i][j-1] : 0) + 1);
        max_v = std::max(max_v, (matrix[i][j] < up ? path1[i-1][j] : 0) + 1);
        path1[i][j] = max_v;
        g_max = std::max(g_max, max_v);
      }
    }
    return g_max;
  }
};

int main()
{
  vector<vector<int>> v = {
    {9,9,4},
    {6,6,8},
    {2,1,1},
  };
  vector<vector<int>> v2 = {
    {7,8,9},
    {9,7,6},
    {7,2,3},
  };
  Solution sol;
  cout << sol.longestIncreasingPath(v) << endl;
  return 0;
}
