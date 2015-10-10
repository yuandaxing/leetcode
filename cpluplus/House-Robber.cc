#include <vector>
using std::vector;

//F[n] = max{F[n-2] + A[n], F[n-1]};
class Solution
{
public:
  int rob(vector<int>& nums)
  {
    if(nums.size() == 0)
      return 0;
    if(nums.size() == 1)
      return nums[0];
    vector<int> F(nums.size(), 0);
    F[0] = nums[0];
    F[1] = std::max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++)
    {
      F[i] = std::max(F[i-1], F[i-2] + nums[i]);
    }
    return F[nums.size() - 1];
  }
};
