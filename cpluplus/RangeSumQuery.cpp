/*
 * author: yuandx
 * create: 2016-05-12
 * email: yuandx@mvad.com
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <string>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using std::unordered_map;
using std::unordered_set;
using std::ostringstream;
using std::istringstream;
using std::stringstream;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::map;
using std::set;
using std::pair;
using std::sort;
using std::string;
using std::for_each;
/*
 * B[i] = A[0]+A[2]+...+A[i]
 * range(i, j) = B[j] - B[i-1]
 */
class NumArray {

public:
  NumArray(vector<int> &nums): nums_(nums)
  {
    sums_.resize(nums_.size());
    for (size_t i = 0; i != nums_.size(); i++)
    {
      sums_[i] += nums[i] + (i > 0 ? sums_[i-1] : 0);
    }
  }

  int sumRange(int i, int j)
  {
    int left = 0;
    if (i > 0)
    {
      left = sums_[i-1];
    }
    return sums_[j] - left;
  }
private:
  vector<int>& nums_, sums_;
};


int main()
{

  return 0;
}
