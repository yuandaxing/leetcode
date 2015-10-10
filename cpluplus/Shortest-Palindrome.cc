#include <string>
#include <algorithm>
using std::reverse;
using std::string;
/*
 * n^2 algorithm, search from right to left, find the longest palindrome,
 * then add from the left to right
 */
class Solution {
public:
  bool IsPalindrome(const string& s, int len)
  {
    int left = 0, right = len - 1;
    while (left < right)
    {
      if (s[left] != s[right])
      {
        return false;
      }
      left++; right--;
    }
    return true;
  }
  string shortestPalindrome(string s) {
    for(int size = s.size(); size >= 0; size--)
    {
      if (IsPalindrome(s, size))
      {
        string result = s.substr(size);
        reverse(result.begin(), result.end());
        return result;
      }
    }
    return "";
  }
};
