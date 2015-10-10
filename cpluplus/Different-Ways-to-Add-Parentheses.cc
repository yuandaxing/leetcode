#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>
#include <stdlib.h>
using std::vector;
using std::map;
using std::set;
using std::string;

/*
 * [0, 1, 2]
 * [-, +]
 * iterator len of the operator
 * 1 to n-1
 *  Val(i, len, set<int>&)
 *
 */
void Print(vector<int>& v)
{
  for (int i = 0; i != v.size(); i++)
    std::cout << v[i] << "\t" ;
  std::cout << std::endl;
}
class Solution {
public:
  typedef int (*op)(int left, int right);
  vector<int> operand_;
  vector<int> operator_;
  map<int, op> ops_;
public:
  void Val(int beg, int len, vector<int>& val)
  {
    if (len == 1)
    {
      val.push_back(operand_[beg]);
      return ;
    }

    for (int i = 1; i < len; i++)
    {
      vector<int> left, right;
      Val(beg, i, left);
      Val(beg + i, len - i, right);
      for (vector<int>::iterator it = left.begin(); it != left.end(); ++it)
      {
        for (vector<int>::iterator it1 = right.begin(); it1 != right.end(); ++it1)
        {
          val.push_back(ops_[operator_[beg+i-1]](*it, *it1));
        }
      }
    }
  }
  static int add(int i, int j)
  {
    return i+j;
  }
  static int mul(int i, int j)
  {
    return i * j;
  }
  static int sub(int i, int j)
  {
    return i - j;
  }
  vector<int> diffWaysToCompute(string input) {
    ops_[0] = add;
    ops_[1] = mul;
    ops_[2] = sub;
    string ops_set = "+-*";
    int prev = 0;
    //std::cout << "here" << std::endl;
    for (int cur = input.find_first_of(ops_set, prev); cur != string::npos; prev = cur + 1, cur = input.find_first_of(ops_set, prev))
    {
      operand_.push_back(atoi(input.substr(prev, cur - prev).c_str()));
      //std::cout << "cur: " << cur << std::endl;
      switch (input[cur])
      {
      case '+': operator_.push_back(0); break;
      case '*': operator_.push_back(1); break;
      case '-': operator_.push_back(2); break;
      default: break;
      }
    }
    operand_.push_back(atoi(input.substr(prev).c_str()));
    vector<int> result;
    Val(0, operand_.size(), result);
    return vector<int>(result.begin(), result.end());
  }
};

int main(int argc, char *argv[])
{
  string a = "2-1-1-1-1";
  Solution sol;
  vector<int> result = sol.diffWaysToCompute(a);
  Print(sol.operand_);
  Print(sol.operator_);
  Print(result);
  return 0;
}
