/*
 * author: yuandx
 * create: 2016-07-11
 * email: yuandx@mvad.com
 */
#include <iostream>
using std::cout;
using std::endl;

int add(int a, int b, int c)
{
  if (a == 0 && b == 0 && c == 0)
    return 0;
  int l_a = a & 1, l_b = b & 1;
  return (l_a ^ l_b  ^ c) | (add(a >> 1, b >> 1, c == 0 ? a & b : (a | b)) << 1);
}

int main(int argc, char *argv[])
{
  cout << add(10, 10, 0)<< endl;
  return 0;
}
