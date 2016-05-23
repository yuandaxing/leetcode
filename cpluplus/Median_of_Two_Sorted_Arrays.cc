/*
 * author: yuandx
 * create: 2015-09-30
 * email: yuandx@mvad.com
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdio.h>
#include <climits>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::map;
using std::set;
using std::pair;
using std::sort;
using std::string;
class Solution
{
public:
  /*
   * mid, k-1-mid, k-2-mid
   */
  bool FindKInV1(vector<int>& v1, vector<int>& v2, int k, int &v)
  {
    int size1 = static_cast<int>(v1.size()), size2 = static_cast<int>(v2.size());
    int left = 0, right = size1 - 1;
    while (left <= right)
    {
      int mid = (left + right) / 2;
      cout << mid << endl;
      int v_length = k - mid - 1; //v1 is length
      if (v_length < 0)
      {
        right = mid - 1;
      }
      else if (v_length > size2)
      {
        left = mid + 1;
      }
      else
      {
        int left_v = v_length == 0 ? INT_MIN : v2[v_length - 1];
        int right_v = v_length == size2 ? INT_MAX : v2[v_length];
        if (v1[mid] < left_v)
        {
          left = mid + 1;
        }
        else if (v1[mid] > right_v)
        {
          right = mid - 1;
        }
        else
        {
          v = v1[mid];
          return true;
        }
      }
    }
    return false;
  }
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
  {
    int size = static_cast<int>(nums1.size() + nums2.size());
    if ((size & 1) == 1)
    {
      int v, K = size / 2 + 1;
      FindKInV1(nums1, nums2, K, v) || FindKInV1(nums2, nums1, K, v);
      return v;
    }
    else
    {
      int v1 = 0, K1 = size / 2;
      int v2 = 0, K2 = size / 2 + 1;
      FindKInV1(nums1, nums2, K1, v1) || FindKInV1(nums2, nums1, K1, v1);
      FindKInV1(nums1, nums2, K2, v2) || FindKInV1(nums2, nums1, K2, v2);
      cout << v1 << "\t" << v2 << endl;
      return (v1 + v2) / 2.0;
    }
  }
};

int main()
{
  Solution sol;
  vector<int> v1 = {1, 2}, v2 = v1;
  cout << sol.findMedianSortedArrays(v1, v2) << endl;
  return 0;
}
