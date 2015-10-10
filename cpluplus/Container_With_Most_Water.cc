/*
 * author: yuandx
 * create: 2015-10-03
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
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::map;
using std::set;
using std::pair;
using std::sort;
using std::string;
/*
 * (A[i], A[j]) (i-j)*min(A[i], A[j])
 *
 */
class Solution
{
public:
  int maxArea(vector<int>& height)
  {
    int i = 0, j = static_cast<int>(height.size()-1);
    int max_area = 0;
    while (i < j)
    {
      max_area = std::max((j-i)*std::min(height[i], height[j]), max_area);
      if (height[i] > height[j])
        j--;
      else
        i++;
    }
    return max_area;
  }
};
int main()
{

  return 0;
}
