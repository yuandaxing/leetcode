/*
 * author: yuandx
 * create: 2016-05-13
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
 *(i, j, i1, j1)
 * for row in i, i1
 *  sum += rangeRegion(row, j, j1);
 *
 * also, we can use matrix (i, j) mean sum region(0, 0, i, j)
 * (i, j, ii, j1) = (i1, j1)- (i1, j-1) - (i-1, j1) + (i-1, j-1)
 */
class NumMatrix
{
public:
  vector<vector<int>> result;
  NumMatrix(vector<vector<int>> &matrix)
  {
    int row = static_cast<int>(matrix.size()),
      col = row > 0 ? static_cast<int>(matrix[0].size()) : 0;
    result.resize(row);
    for (int i = 0; i  < row; i++)
    {
      result[i].resize(col);
      for (int j = 0; j < col; j++)
      {
        int top_left = (i-1 >= 0 && j-1>=0) ? result[i-1][j-1] : 0,
          top_up = (i-1>=0) ? result[i-1][j] : 0,
          left = (j-1>=0) ? result[i][j-1] : 0;
        result[i][j] = left + top_up - top_left + matrix[i][j];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2)
  {
    int left = (col1 - 1 >= 0) ? result[row2][col1-1]: 0,
      up = (row1 - 1 >= 0) ? result[row1-1][col2]: 0,
      up_left = (row1-1>=0 && col1-1>=0) ? result[row1-1][col1-1] : 0;
    return result[row2][col2] - left - up + up_left;
  }
};
int main()
{
  vector<vector<int>> vec = {
    {3, 0, 1, 4, 2},
    {5, 6, 3, 2, 1},
    {1, 2, 0, 1, 5},
    {4, 1, 0, 1, 7},
    {1, 0, 3, 0, 5}
  };
  NumMatrix nm(vec);
  cout << nm.sumRegion(2, 1, 4, 3) << endl;
  cout << nm.sumRegion(1, 1, 2, 2) << endl;
  cout << nm.sumRegion(1, 2, 2, 4) << endl;
  return 0;
}
