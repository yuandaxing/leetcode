#include <vector>
#include <utility>
#include <list>
using std::pair;
using std::vector;
using std::list;
//descending queue

/*
 * for i in i...nums.size();
 *  front = result.front();
 *  if i - front.second >= k
 *    front.pop_front()
 *    while !result.empt()
 *        back = result.back();
 *       if back.first < nums[i]:
 *          result.pop_back()
 *    result.push_back(nums[i]);
 *   front = result.front()
 *   final.push_back(front.first);
 */
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k)
  {
    vector<int> result;
    list<pair<int, int> > tmp;
    if (nums.size() == 0) return result;
    tmp.push_back(pair<int, int>(nums[0], 0));
    if (k == 1)
      result.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
      pair<int, int>& front = tmp.front();
      if (i - front.second >= k)
        tmp.pop_front();
      while (!tmp.empty())
      {
        pair<int, int>& back = tmp.back();
        if (back.first < nums[i])
        {
          tmp.pop_back();
        }
        else
          break;
      }
      tmp.push_back(pair<int, int>(nums[i], i));
      if (i >= k - 1)
        result.push_back(tmp.front().first);
    }
    return result;
  }
};
