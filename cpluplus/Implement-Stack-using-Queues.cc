/*
 * author: yuandx
 * create: 2016-07-06
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
#include <list>
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
class Stack {
public:
    // Push element x onto stack.
  void push(int x) 
  {
    top_ = x;
    Q1.push_back(x);
  }

  // Removes the element on top of the stack.
  void pop() 
  {
    while (Q1.size() != 1)
    {
      top_ = Q1.front();
      Q2.push_back(Q1.front());
      Q1.pop_front(); 
    }
    Q1.pop_front();
    Q1.swap(Q2);
  }

  // Get the top element.
  int top() 
  {
	return top_;
  }

  // Return whether the stack is empty.
  bool empty() 
  {
    return Q1.empty();
  }
private:
  int top_;
  std::list<int> Q1;
  std::list<int> Q2;
};
