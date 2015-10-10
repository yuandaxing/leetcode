#include <iostream>
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        while ((n & 1) == 0) n >>= 1;
        return (n >> 1) == 0;
    }
};

int main(int argc, char *argv[])
{
  Solution sol;
  std::cout << sol.isPowerOfTwo(2) << std::endl;
  return 0;
}
