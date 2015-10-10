#include <vector>
#include <algorithm>
#include <functional>
using std::nth_element;
using std::vector;
class Solution
{
public:
  int findKthLargest(vector<int>& nums, int k)
  {
    nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), std::greater<int>());
    return *(nums.begin() + k - 1);
  }
};
