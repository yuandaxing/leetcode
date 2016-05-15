/*
 * author: yuandx
 * create: 2016-05-13
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
 *(i, j, i1, j1)
 * for row in i, i1
 *  sum += rangeRegion(row, j, j1);
 *
 * also, we can use matrix (i, j) mean sum region(0, 0, i, j)
 * (i, j, ii, j1) = (i1, j1)- (i1, j-1) - (i-1, j1) + (i-1, j-1)
 */
class Solution
{
public:

};

int main()
{

  return 0;
}
