/*
 * author: yuandx
 * create: 2016-04-11
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
#include <atomic>
#include <future>
#include <thread>
#include <mutex>
#include <chrono>
#include <unordered_map>
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
using std::atomic;
using std::thread;
using std::future;
using std::promise;
const std::unordered_map<int, string> int_2_words =
  {
    {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"},
    {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"}, {11, "Eleven"},
    {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"},
    {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"},
    {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}
  };
class Solution {
public:
  string Parse1000(int num)
  {
    ostringstream os;
    if (num >= 100)
    {
      auto it = int_2_words.find(num / 100);
      os << it->second << " Hundred ";
      num %= 100;
    }
    if (num > 0)
    {
      auto it = int_2_words.find(num);
      if (it != int_2_words.end())
      {
        os << it->second << " ";
      }
      else
      {
        it = int_2_words.find((num / 10) * 10);
        os << it->second << " ";
        it = int_2_words.find(num % 10);
        os <<  it->second << " ";
      };
    }
    return os.str();
  }
  string numberToWords(int num)
  {
    vector<string> vec_str = {"Thousand", "Million", "Billion"};
    int idx = 2, v = 1e9;
    for (; v > num; v /= 1000, idx--);
    ostringstream os;
    for (; idx >= 0; idx--)
    {
      if (num >=  v)
      {
        os << Parse1000(num / v) << vec_str[idx] << " ";
        num %= v;
      }
      v /= 1000;
    }
    if (num > 0)
    {
      os << Parse1000(num);
    }
    string result =  os.str();
    size_t last_pos = result.find_last_not_of(" ");
    if (last_pos != string::npos)
    {
      result.resize(last_pos + 1);
    }
    return result;
  }
};

int main()
{
  Solution s;
  cout << s.numberToWords(1234567) << endl;
  cout << s.numberToWords(12345) << endl;
  cout << s.numberToWords(123) << endl;
  cout << s.numberToWords(100) << endl;
  return 0;
}
