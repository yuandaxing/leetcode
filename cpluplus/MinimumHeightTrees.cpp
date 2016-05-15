/*
 * author: yuandx
 * create: 2016-05-15
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
 * all pairs shortest path O(n3)
 *  ballman ford algorithm
 * for row in rows
 * for col in cols:
    for k in nodes:
     if F[row, k] [k, col]
        F[row][col] = std::min(F[row][col], F[row][k] + F[k][col])
 *
 *
 *
 */

class Solution
{
public:

};

int main()
{

  return 0;
}
