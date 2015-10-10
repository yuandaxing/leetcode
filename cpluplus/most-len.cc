#include <iostream>
#include <map>
#include <string>
using std::string;
using std::cout;
using std::map;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
       map<char, int> c_2_count;
       int begin = 0, end = 0, max_len = 0;
       for (; begin != s.size(); ++begin)
       {
           while(c_2_count.size() <= 2 && end != s.size())
           {
               c_2_count[s[end]] += 1;
               end++;
           }
           max_len = std::max(end - begin, max_len);
           c_2_count[s[begin]] -= 1;
           if (c_2_count[s[begin]] == 0)
           {
               c_2_count.erase(s[begin]);
           }
       }
       return max_len;
    }
  int lengthOfLongestSubstringTwoDistinct1(string s) {
    map<char, int> c_2_count;
    int begin = 0, end = 0, max_len = 0;
    for (; end != s.size(); ++end)
    {
      c_2_count[s[end]] += 1;
      while(c_2_count.size() > 2)
      {
        c_2_count[s[begin]] -= 1;
        if (c_2_count[s[begin]] == 0)
        {
          c_2_count.erase(s[begin]);
        }
        begin++;
      }
      max_len = std::max(end - begin + 1, max_len);
    }
    return max_len;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;
  string s = "abc";
  cout << sol.lengthOfLongestSubstringTwoDistinct(s) << std::endl;
  cout << sol.lengthOfLongestSubstringTwoDistinct1(s) << std::endl;
  return 0;
}
