#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <stdlib.h>

using std::string;
using std::map;

class Solution {
public:
  string Normalize(string ret, bool isPositive)
  {
    if (isPositive) return ret;
    ret.insert(0, "-");
    return ret;
  }
  string fractionToDecimal(int numerator, int denominator)
  {
    long numerator_l = numerator, denominator_l = denominator;
    bool positive = (numerator_l * denominator_l >= 0);
    numerator_l = abs(numerator_l), denominator_l = abs(denominator_l);
    string ret;
    map<long, long> numerator_l2Pos;
    long v = numerator_l / denominator_l;
    char tmp[128] = {0};
    numerator_l = numerator_l % denominator_l;
    snprintf(tmp, sizeof(tmp), "%ld", v);
    ret.append(tmp);
    if (numerator_l == 0) return Normalize(ret, positive);
    ret.push_back('.');
    while (numerator_l != 0)
    {
      if (numerator_l2Pos.find(numerator_l) != numerator_l2Pos.end())
      {
        ret.push_back(')');
        ret.insert(numerator_l2Pos[numerator_l], "(");
        break;
      }
      numerator_l2Pos[numerator_l] = ret.size();
      numerator_l *= 10;
      ret.push_back('0' + numerator_l / denominator_l);
      numerator_l %= denominator_l;
    }
    return Normalize(ret, positive);
  }
};
