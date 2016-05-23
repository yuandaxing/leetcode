/*
 * author: yuandx
 * create: 2016-05-22
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
struct IdxVal
{
  int idx_;
  int val_;
  IdxVal(int idx, int val):
    idx_(idx), val_(val)
  {
  }
};

#define ROT32(x, y) ((x << y) | (x >> (32 - y))) // avoid effort
uint32_t murmur3_32(const char *key, uint32_t len, uint32_t seed)
{
  static const uint32_t c1 = 0xcc9e2d51;
  static const uint32_t c2 = 0x1b873593;
  static const uint32_t r1 = 15;
  static const uint32_t r2 = 13;
  static const uint32_t m = 5;
  static const uint32_t n = 0xe6546b64;

  uint32_t hash = seed;

  const int nblocks = len / 4;
  const uint32_t *blocks = (const uint32_t *) key;
  int i;
  uint32_t k;
  for (i = 0; i < nblocks; i++)
  {
    k = blocks[i];
    k *= c1;
    k = ROT32(k, r1);
    k *= c2;

    hash ^= k;
    hash = ROT32(hash, r2) * m + n;
  }

  const uint8_t *tail = (const uint8_t *) (key + nblocks * 4);
  uint32_t k1 = 0;

  switch (len & 3)
  {
    case 3:
      k1 ^= tail[2] << 16;
    case 2:
      k1 ^= tail[1] << 8;
    case 1:
      k1 ^= tail[0];

      k1 *= c1;
      k1 = ROT32(k1, r1);
      k1 *= c2;
      hash ^= k1;
  }

  hash ^= len;
  hash ^= (hash >> 16);
  hash *= 0x85ebca6b;
  hash ^= (hash >> 13);
  hash *= 0xc2b2ae35;
  hash ^= (hash >> 16);

  return hash;
}
size_t Hasher(const IdxVal& iv)
{
  return murmur3_32(reinterpret_cast<const char*>(&iv), sizeof(iv), 0);
}
bool Equal(const IdxVal& i1, const IdxVal& i2)
{
  return i1.idx_ == i2.idx_ && i1.val_ == i2.val_;
}
class Solution
{
public:
  std::unordered_set<IdxVal> memo(100);
  vector<vector<int>> permuteUnique(vector<int>& nums)
  {
    vector<vector<int>> result;
    return result;
  }
};

int main()
{

  return 0;
}
