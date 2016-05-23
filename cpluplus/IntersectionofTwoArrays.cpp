/*
 * author: yuandx
 * create: 2016-05-19
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
template <typename int_type>
void SortUniqVector(std::vector<int_type>& vec)
{
  if (vec.size() == 0u)
  {
    return ;
  }
  sort(vec.begin(), vec.end());
  int insert_pos = 1;
  for (size_t i = 1; i < vec.size(); i++)
  {
    if ( vec[i-1] != vec[i] )
    {
      vec[insert_pos++] = vec[i];
    }
  }
  vec.resize(insert_pos);
}

class Solution
{
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
  {
    SortUniqVector(nums1);
    SortUniqVector(nums2);
    vector<int> result;
    for (auto iter1 = nums1.begin(), iter2 = nums2.begin(); iter1 != nums1.end() && iter2 != nums2.end(); )
    {
      int v1 = *iter1, v2 = *iter2;
      if (v1 < v2)
      {
        ++iter1;
      } else if (v1 > v2)
      {
        ++iter2;
      } else
      {
        result.push_back(v1);
        ++iter1;
        ++iter2;
      }
    }
    return result;
  }
};

int main()
{
  Solution s;
  vector<int> v1 = {1}, v2 = {1}, v3 = s.intersection(v1, v2);
  for (auto it = v3.begin(); it != v3.end(); ++it)
  {
    cout << *it << " ";
  }
  cout << endl;
  return 0;
}
