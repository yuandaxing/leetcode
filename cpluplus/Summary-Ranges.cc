#include <stdio.h>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution
{
public:
  vector<string> summaryRanges(vector<int>& nums)
  {
    vector<string> ret;
    int prev = 0;
    if (nums.size() == 0) return ret;
    for (int i = 0; i <= nums.size(); i++)
    {
      if(i == nums.size() || nums[i] - nums[prev] != i - prev)
      {
        int before = i - 1;
        char a[100] = {0};
        if (before == prev)
        {
          snprintf(a, sizeof(a), "%d", nums[prev]);

        } else
        {
          snprintf(a, sizeof(a), "%d->%d", nums[prev], nums[before]);
        }
        ret.push_back(a);
        prev = i;
      }
    }
    return ret;
  }
};
