#include <string>
#include <iostream>
using std::cout;
using std::string;

class Solution
{
public:
  void reverse(string& s, int i, int j)
  {
    for (; i < j; i++, j--)
    {
      std::swap(s[i], s[j]);
    }
  }
  void reverseWords(string &s)
  {
    reverse(s, 0, s.size() - 1);
    int i = 0, j;
    do
    {
      j = s.find_first_of(' ', i);
      reverse(s, i, j < 0 ? s.size() - 1 : j - 1);
      i = j + 1;
    } while (j != -1);
  }
};

int main(int argc, char *argv[])
{
  Solution sol;
  string test = "a b";
  sol.reverseWords(test);
  cout << test << std::endl;
  return 0;
}
