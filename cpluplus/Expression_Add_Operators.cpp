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
template <typename V>
void DumpVec(const vector<V>& v)
{
  for (auto it = v.begin(); it != v.end(); ++it)
  {
    cout << *it << " ";
  }
  cout << endl;
}
using FunType = std::function<int(int, int)>;
vector<FunType> binary_func = {
  [](int i, int j){ return i + j; },
  [](int i, int j){ return i - j; },
  [](int i, int j){ return i * j; }
};
vector<char> operator_char = {'+', '-', '*'};
class Solution
{
public:
  int V_;

  bool IsValid(const vector<int>& nums, vector<int>& ops)
  {
    vector<int> result = {nums[0]};
    vector<int> op;
    for (size_t i = 0; i != ops.size(); i++)
    {
      result.push_back(nums[i+1]);
      if (ops[i] == 2)
      {
        int right = result.back();
        result.pop_back();
        int left = result.back();
        result.pop_back();
        result.push_back(binary_func[2](left, right));
      }
      else
      {
        op.push_back(ops[i]);
      }
    }
    if (op.empty())
    {
      return result.back() == V_;
    }
    int value = result[0];
    for (size_t i = 0; i != op.size(); i++)
    {
      value = binary_func[op[i]](value, result[i+1]);
    }
    return value == V_;
  }

  void Try(vector<int>& nums, int pos,
           vector<int>& cur, vector<vector<int>>& result)
  {
    int size = static_cast<int>(nums.size());
    if (size == pos)
    {
      if (IsValid(nums, cur))
      {
        result.push_back(cur);
      }
      return ;
    }
    for (size_t i = 0; i != binary_func.size(); i++)
    {
      cur.push_back(i);
      Try(nums, pos+1, cur, result);
      cur.pop_back();
    }
  }
  void Split(vector<int>& nums, int pos, vector<int>& cur, vector<vector<int>>& result)
  {
    int size = static_cast<int>(nums.size());
    if (pos == size)
    {
      result.push_back(cur);
      return ;
    }
    int val = 0;
    bool only_one = (nums[pos] == 0);
    for (; pos < size; pos++)
    {
      val = val * 10 + nums[pos];
      cur.push_back(val);
      Split(nums, pos+1, cur, result);
      cur.pop_back();
      if (only_one)
        break;
    }
  }

  vector<string> addOperators(string num, int target)
  {
    V_ = target;
    vector<string> result;
    vector<int> vec;
    for (auto it = num.begin(); it != num.end(); ++it)
    {
      vec.push_back(*it - '0');
    }
    vector<vector<int>> vec_splits, ops;
    vector<int> tmp;
    Split(vec, 0, tmp, vec_splits);
    for (auto it = vec_splits.begin(); it != vec_splits.end(); ++it)
    {
      ops.clear();
      Try(*it, 1, tmp, ops);
      for (auto ito = ops.begin(); ito != ops.end(); ++ito)
      {
        ostringstream os;
        os << (*it)[0];
        for (size_t i = 0; i != ito->size(); ++i)
        {
          os << operator_char[(*ito)[i]];
          os << (*it)[i+1];
        }
        result.push_back(os.str());
      }
    }
    return result;
  }
};

int main()
{
  Solution s;
  vector<string> result = s.addOperators("123456789", 45);
  for (auto it = result.begin(); it != result.end(); ++it)
  {
    cout << *it << endl;
  }
  return 0;
}
