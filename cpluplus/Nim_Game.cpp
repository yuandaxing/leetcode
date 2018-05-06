/*
 * author: yuandx
 * create: 2015-10-16
 * email: yuandx@mvad.com
 */
/*
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
  F[1] = F[2] = F[3]
  F[4] = false
  F[5] = F[6] = F[7]
  F[8] = false
  F[9] = F[10] = f[11]

 */

class Solution
{
public:
  bool canWinNim(int n)
  {
    vector<int> win_matrix(4);
    win_matrix[0]=win_matrix[1]=win_matrix[2]=win_matrix[3]=true;
    for (int i = 4; i <= n; i++)
    {
      if (win_matrix[(i-1)%4] && win_matrix[(i-2)%4] && win_matrix[(i-3)%4])
        win_matrix[i%4] = false;
      else
        win_matrix[i%4] = true;
    }
    return win_matrix[n%4];
  }
};

int main()
{
  Solution sol;
  cout << sol.canWinNim(4) << endl;
  cout << sol.canWinNim(5) << endl;
  cout << sol.canWinNim(1348820612) << endl;
  return 0;
}
