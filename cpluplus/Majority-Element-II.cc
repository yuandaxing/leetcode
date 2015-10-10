#include <algorithm>
#include <vector>
#include <map>
using std::map;
using std::vector;
using std::nth_element;
/*
 * n / 3 n/6
 * nth_element()
 */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      int n = nums.size();
      nth_element(nums.begin(), nums.begin() + n / 3, nums.end());
      nth_element(nums.begin() + n / 3 + 1, nums.begin() + n/3 * 2, nums.end());
      nth_element(nums.begin() + n/3 * 2 + 1, nums.begin() + n / 3 * 3, nums.end());
      map<int, int> vc;
      vc[nums[0]] = vc[nums[n/3]] = vc[nums[n/3*2]] = vc[nums[n/3*3]] = vc[nums[n-1]] = 0;
      for (int i = 0; i != nums.size(); i++)
      {
        map<int, int>::iterator it = vc.find(nums[i]);
        if (it != vc.end())
        {
          it->second += 1;
        }
      }
      vector<int> result;
      for (map<int, int>::iterator it = vc.begin(); it != vc.end(); ++it)
      {
        if (it->second > n / 3)
        {
          result.push_back(it->first);
        }
      }
      return result;
    }
};
