/*
 * author: yuandx
 * create: 2016-05-13
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
 * update i, value, i should i update all the sum after i
 *
 */
class NumArray {
public:
  vector<int> nums_;
  vector<int> sums_;
  void UpdateRange(int start)
  {
    int size = static_cast<int>(sums_.size());
    for (; start < size; start++)
    {
      int prev = start > 0 ? sums_[start-1]: 0;
      sums_[start] = nums_[start] + prev;
    }
  }

  NumArray(vector<int> &nums):
    nums_(nums)
  {
    sums_.resize(nums.size(), 0);
    UpdateRange(0);
  }

  void update(int i, int val)
  {
    nums_[i] = val;
    UpdateRange(i);
  }

  int sumRange(int i, int j)
  {
    int prev = i > 0 ? sums_[i-1] : 0;
    return sums_[j] - prev;
  }
};

int main()
{
  vector<int> v = {1, 3, 5};
  NumArray ar(v);
  cout << ar.sumRange(0, 2) << endl;
  ar.update(1, 2);
  cout << ar.sumRange(0, 2) << endl;
  return 0;
}
