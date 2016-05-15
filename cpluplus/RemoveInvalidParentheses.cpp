/*
 * author: yuandx
 * create: 2016-05-12
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
 *()())(  left[i] < right[i] if right[size] > left[size]
 *(a)())() ["(a)()()", "(a())()"]
 *m )(
 * stack, how many ) should be removed, and how many ( should be removed
 *
 * 1. remove the rightmost "("
 * 2. use stack to calculate how many ")" should be removed
 * 3. get the ")" position
 * 4. use the selection algorithm
 */
class Solution
{
public:

};

int main()
{

  return 0;
}
