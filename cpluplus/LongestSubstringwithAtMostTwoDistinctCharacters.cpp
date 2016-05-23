/*
 * author: yuandx
 * create: 2016-05-15
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
  int lengthOfLongestSubstringTwoDistinct(string s)
  {
    map<char, int> v_freq;
    int start = 0, size = static_cast<int>(s.size());
    int length = 0;
    for (int i = 0; i < size; i++)
    {
      v_freq[s[i]] += 1;
      while (v_freq.size() > 2u)
      {
        v_freq[s[start]] -= 1;
        if (v_freq[s[start]] == 0)
        {
          v_freq.erase(s[start]);
        }
        start++;
      }
      length = std::max(i - start + 1, length);
    }
    return length;
  }
};

int main()
{
  string v1 = "eceba";
  Solution s;
  cout << s.lengthOfLongestSubstringTwoDistinct(v1) << endl;

  return 0;
}
