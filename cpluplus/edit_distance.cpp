/*
 * author: yuandx
 * create: 2016-07-05
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
/*
 * F[i][j] = min{F[i-1][j-1] if A[i] == A[j], F[i][j-1]+1, F[i-1][j]+1, F[i-1][j-1]+1 };
 */
class Solution
{
public:
  int minDistance(string word1, string word2)
  {
    vector<vector<int>> F(word1.size()+1, vector<int>(word2.size()+1, 0));
    int size1 = word1.size(), size2 = word2.size();
    for (int i = 0; i <= size1; i++)
    {
      for (int j = 0; j <= size2; j++)
      {
        if (i == 0)
        {
          F[i][j] = j;
          continue;
        }
        if (j == 0)
        {
          F[i][j] = i;
          continue;
        }
        F[i][j]= F[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1);
        F[i][j] = std::min(F[i][j-1] + 1, F[i][j]);
        F[i][j] = std::min(F[i-1][j]+1, F[i][j]);
      }
    }
    return F[word1.size()][word2.size()];
  }
};

int main()
{

  return 0;
}
