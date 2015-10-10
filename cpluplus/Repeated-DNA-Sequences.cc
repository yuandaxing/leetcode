#include <map>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::map;
class Solution
{
public:
  int char2int(char v)
  {
    switch (v)
    {
    case 'A': return 0;
    case 'C': return 1;
    case 'G': return 2;
    case 'T': return 3;
    }
    return 10;
  }
  int encode(string& str, int i)
  {
    int ret = 0;
    for (int j = i - 9; j != i + 1; j++)
    {
      ret = ret << 2 | char2int(str[j]);
    }
    return ret;
  }
  vector<string> findRepeatedDnaSequences(string s)
  {
    map<int, int> s2occur;
    vector<string> ret;
    if (s.size() < 10) return ret;
    for (int i = 9; i != s.size(); i++)
    {
      int z = encode(s, i);
      int occur = (s2occur[z] += 1);
      if (occur == 2)
      {
        ret.push_back(s.substr(i-9, 10));
      }
    }
    return ret;
  }
};
