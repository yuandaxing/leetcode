class Solution
{
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target)
  {
    if (matrix.size() == 0)
      return false;
    int row = matrix.size(), col = matrix[0].size();
    int i = 0, j = col - 1;
    while (i != row && j >= 0)
    {
      if (matrix[i][j] > target)
      {
        j -= 1;
      }
      else  if (matrix[i][j] < target)
      {
        i += 1;
      }
      else
      {
        return true;
      }
    }
    return false;
  }
};
