#include <iostream>
#include <vector>
using std::vector;
class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0, j = numbers.size() - 1;
    vector<int> ret;
    while (i < j)
    {
      int sum = numbers[i] + numbers[j];
      if (sum < target)
        i++;
      else if (sum > target)
        j--;
      else
      {
        ret.push_back(i+1);
        ret.push_back(j+1);
        break;
      }
    }
    return ret;
  }
};
