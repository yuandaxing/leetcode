#include <vector>
#include <algorithm>
using std::min;
using std::vector;
/*
 * F[x][y][k] = F[x][y][k-1] & F[x+1][y+1][k-1] & F[x+1][y][k-1] & F[x][y+1][k-1]
 * O(M*N*min(M,N))
 *
 */
int maximalSquare(vector<vector<char>>& matrix)
{
  int row = matrix.size(), col = row == 0 ? 0 : matrix[0].size();
  vector<vector<vector<bool> > > F(row, vector<vector<bool>
                                   >(col, vector<bool>(min(row, col), false)));
  int max_len = 0;
  for (int i = 0; i != row; i++)
  {
    for (int j = 0; j != col; j++)
    {
      if (matrix[i][j] == '1')
      {
        F[i][j][0] = true;
        max_len = 1;
      }
    }
  }

  for (int k = 2; k <= min(row, col); k++)
  {
    bool found = false;
    for (int i = 0; i != row - k + 1; i++)
    {
      for (int j = 0; j != col - k + 1; j++)
      {
        F[i][j][k-1] = F[i][j][k-2] && F[i+1][j+1][k-2] &&
          F[i+1][j][k-2] &&  F[i][j+1][k-2];
        found = F[i][j][k-1] || found;
      }
    }
    if (found == false)
    {
      break;
    }
    else
    {
      max_len++;
    }
  }
  return max_len * max_len;
}

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

    }
};
