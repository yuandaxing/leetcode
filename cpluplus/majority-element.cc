#include <algorithm>
#include <vector>
using std::vector;
class Solution
{
public:
  int majorityElement(vector<int>& nums)
  {
    int k = nums.size() / 2;
    std::nth_element(nums.begin(), nums.begin() + k,  nums.end());
    return nums[k];
  }
};
