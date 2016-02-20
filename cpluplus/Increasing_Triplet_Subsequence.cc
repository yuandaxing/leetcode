/*
 * author: yuandx
 * create: 2016-02-20
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
class Solution
{
public:
  void insert(vector<int>& v, int i)
  {
    auto it = find_if(v.begin(), v.end(), [i](int v){
        return v >= i;
      });
    if (it == v.end())
    {
      v.push_back(i);
    }
    else
    {
      *it = i;
    }
  }
  bool increasingTriplet(vector<int>& nums)
  {
    vector<int> queue;
    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
      insert(queue, *it);
      if (queue.size() == 3)
      {
        return true;
      }
    }
    return false;
  }
};

int main()
{

  return 0;
}
