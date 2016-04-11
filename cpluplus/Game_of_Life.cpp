/*
 * author: yuandx
 * create: 2016-04-12
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

vector<vector<int>> direction = {
  {0, -1},
  {0, 1},
  {-1, -1},
  {-1, 0},
  {-1, 1},
  {1, 0},
  {1, 1},
  {1, -1}
};
class Solution
{
public:
  int M_, N_;
  int ValidNeighbor(vector<vector<int>>& board, int i, int j)
  {
    int count = 0;
    for (auto it = direction.begin(); it != direction.end(); ++it)
    {
      int x = i + (*it)[0], y = j + (*it)[1];
      if (x >= 0 && x < M_ && y >= 0 && y < N_)
      {
        count += ((board[x][y]&1) == 1) ? 1 : 0;
      }
    }
    return count;
  }
  void gameOfLife(vector<vector<int>>& board)
  {
    M_ = static_cast<int>(board.size());
    N_ = M_ > 0 ? static_cast<int>(board[0].size()) : 0;
    for (int i = 0; i < M_; i++)
    {
      for (int j = 0; j < N_; j++)
      {
        int v = board[i][j], live = ValidNeighbor(board, i, j);
        int result = 0;
        if (v == 1)
        {
          if (live < 2)
          {
            result = 0;
          }
          else if (live == 2 || live == 3)
          {
            result = 1;
          }
          else
          {
            result = 0;
          }
        }
        else
        {
          if (live == 3)
          {
            result = 1;
          }
        }
        board[i][j] = v | (result << 1);
      }
    }

    for (int i = 0; i < M_; i++)
    {
      for (int j = 0; j < N_; j++)
      {
        board[i][j] >>= 1;
      }
    }
  }
};

int main()
{

  return 0;
}
