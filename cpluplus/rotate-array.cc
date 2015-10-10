#include <vector>
using std::vector;
class Solution
{
public:
  void rotate(vector<int>& nums, int k)
  {
    k = k % nums.size();
    vector<int> out(k, 0);
    for (int i = nums.size() - 1; i != -1; i--)
    {
      int next = i + k;
      if (next < nums.size())
      {
        nums[next] = nums[i];
      }
      else
      {
        out[next - nums.size()] = nums[i];
      }
    }
    for (int i = 0;  i != out.size(); i++)
    {
      nums[i] = out[i];
    }
  }
};
