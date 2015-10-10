#include <vector>
using std::vector;

class Solution
{
public:
  void Mark0(vector<vector<char> >& grid, int i, int j)
  {
    int move[4][2] = { {1, 0}, {0, 1},
                       {-1, 0}, {0, -1}};
    if (i <0 || j < 0 || i >= grid.size() || j >= grid[0].size())
    {
      return ;
    }
    if (grid[i][j] == '0')
    {
      return ;
    }
    grid[i][j] = '0';
    for (int k = 0; k != 4; k++)
    {
      Mark0(grid, i+move[k][0], j+move[k][1]);
    }
  }
  int numIslands(vector<vector<char>>& grid)
  {
    int count = 0;
    for (int i = 0; i != grid.size(); i++)
    {
      for (int j = 0; j != grid[i].size(); j++)
      {
        if (grid[i][j] == '1')
        {
          count += 1;
          Mark0(grid, i, j);
        }
      }
    }
    return count;
  }
};
