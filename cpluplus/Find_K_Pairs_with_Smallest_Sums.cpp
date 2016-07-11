/*
 * author: yuandx
 * create: 2016-07-08
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
#include <queue>
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
using std::priority_queue;
/*
 * A[i] + B[j]
 * i+1, 0
 * B[j]
 * A[i+1]
 */
struct Element
{
  int i1, i2;
  int size;
  bool IsValid() const
  {
    return i2 < size;
  }
  void Incr()
  {
    ++i2;
  }
  Element(int i, int s):
    i1(i), i2(0), size(s)
  {}
};
class Solution
{
public:
  vector<pair<int, int>> kSmallestPairs(vector<int>& nums1,
                                        vector<int>& nums2, int k)
  {
    auto compare = [&nums1, &nums2](const Element&lhs, const Element& rhs)
      {
        return nums1[lhs.i1] + nums2[lhs.i2] > nums1[rhs.i1]+nums2[rhs.i2];
      };
    std::priority_queue<Element, std::vector<Element>, decltype(compare)> q3(compare);
    int size1 = static_cast<int>(nums1.size());
    for (int i = 0;  i < size1; i++)
    {
      Element e(i, nums2.size());
      if (e.IsValid())
      {
        q3.push(e);
      }
    }
    vector<pair<int, int>> result;
    while (!q3.empty() && static_cast<int>(result.size()) < k)
    {
      Element e = q3.top();
      q3.pop();
      result.push_back({nums1[e.i1], nums2[e.i2]});
      e.Incr();
      if (e.IsValid())
      {
        q3.push(e);
      }
    }
    return result;
  }
};

int main()
{
  vector<int> v1 = {1,1,2}, v2 = {1,2,3} ;
  Solution s;
  vector<pair<int, int>> result = s.kSmallestPairs(v1, v2, 10);
  for (auto it = result.begin(); it != result.end(); ++it)
  {
    cout << "(" << it->first << "," << it->second << ") ";
  }
  cout << endl;


  return 0;
}
