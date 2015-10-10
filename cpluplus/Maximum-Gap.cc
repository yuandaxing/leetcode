#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
  int maximumGap(vector<int>& nums)
  {
    if (nums.size() < 2) return 0;
    std::sort(nums.begin(), nums.end());
    int max = 0;
    for (int i = 1; i != nums.size(); i++)
    {
      max = max(max, nums[i] - nums[i-1]);
    }
    return max;
  }
};
