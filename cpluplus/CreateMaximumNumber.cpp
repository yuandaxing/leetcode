/*
 * author: yuandx
 * create: 2016-06-04
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
 * [3, 4, 6, 5]
 * [9, 1, 2, 5, 8, 3]
 * K = 5;
 * algorithm :
 * (9, 0), (8, 4) (5, 3) (3, 5), (2, 2), (1, 1)
 * (6, 2), (5, 3), (4, 1), (3, 0)
 */
class Solution
{
  vector<pair<int, int>> v_pos1, v_pos2;
  int size1, size2, K;
  vector<vector<int, int>> result;
  void Aux(int i, int j, int pos1, int pos2, vector<int>& tmp)
  {
    if (size1 - pos1 + size2 - pos2 == K)
    {
      vector<int> cur(tmp);

    }
    int ret_size = static_cast<int>(tmp.size());
    while(v_pos1[i].second < pos1 && i < size1)
    {
      i++;
    }
    while(v_pos2[j].second < pos2 && j < size2)
    {
      ++j;
    }
  }
public:
  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
  {
    for (int i = 0; i < size1; i++)
    {
      v_pos1.push_back({nums1[i], i});
    }
    for (int i = 0; i < size2; i++)
    {
      v_pos2.push_back({nums2[i], i});
    }
    sort(v_pos1.begin(), v_pos1.end());
    sort(v_pos2.begin(), v_pos2.end());
    int pos1 = 0, pos2 = 0;
    for (auto it = v_pos1.begin(), it2 = v_pos2.begin(); it != v_pos1.end() && it2 != v_pos2.end();)
    {
      int ret_size = static_cast<int>(result.size());
      if (it->second < pos1)
      {
        ++it;
        continue;
      }
      if (it2->second < pos2)
      {
        ++it2;
        continue;
      }

      int v1 = size1 - it->second + size2 - pos2 + ret_size;
      int v2 = size2 - it2->second + size1 - pos1 + ret_size;
      if (it->first > it2->first)
      {
        if ( v1 >= k )
        {
          result.push_back(it->first);
          pos1 = it->second + 1;
        }
        ++it;
      } else if (it->first < it2->first)
      {
        if (v2 >= k )
        {
          result.push_back(it2->first);
          pos2 = it2->second + 1;
        }
        ++it2;
      }
      else
      {

      }
    }
  };

int main()
{

  return 0;
}
