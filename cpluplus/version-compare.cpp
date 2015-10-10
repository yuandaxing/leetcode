#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::vector;

class Solution {
public:
  std::vector<std::string> Split(const std::string& s, const std::string& delim)
{
  std::vector<std::string> ret;
  int start = 0, next = 0;
  do
  {
    next = s.find_first_of(delim, start);
    ret.push_back(s.substr(start, next - start));
    start = next + 1;
  } while (next != std::string::npos);
  return ret;
}
  int convert(int result)
  {
    if (result == 0) return 0;
    return result > 0 ? 1 : -1;
  }

  int subversionComp(string& v1, string& v2)
  {
    v1.erase(0, v1.find_first_not_of("0", 0));
    v2.erase(0, v2.find_first_not_of("0", 0));
    int ret = v1.size() - v2.size();
    if (ret != 0) return convert(ret);
    for (int i = 0; i != v1.size(); i++)
    {
      if (v1[i] != v2[i])
        return convert(v1[i] - v2[i]);
    }
    return 0;
  }

  int compareVersion(string version1, string version2) {
    vector<string> v1 = Split(version1, "."), v2 = Split(version2, ".");
    if(v1.size() < v2.size())
      v1.resize(v2.size());
    else
      v2.resize(v1.size());
    for (int i = 0;  i != v1.size(); i++)
    {
      int ret = subversionComp(v1[i], v2[i]);
      if (ret != 0)
        return ret;
    }
    return 0;
  }
};

int main(int argc, char *argv[])
{
  Solution sol;
  std::cout << sol.compareVersion("1.0", "1.0");
  std::cout << std::endl;
  return 0;
}
