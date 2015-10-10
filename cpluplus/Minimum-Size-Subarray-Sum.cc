#include <vector>
using std::vector;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
      int max = nums.size() + 1, sum = 0;
      for (int beg = 0, end = 0; end != nums.size(); end++)
      {
        sum += nums[end];
        while (sum >= s)
        {
          max = std::min(max, end - beg + 1);
          sum -= nums[beg];
          beg++;
        }
      }
      return max > nums.size() ? 0 : max;
    }
};
