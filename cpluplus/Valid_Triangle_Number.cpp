/*
 * author: daxing.yuan
 * create: 2017-10-13
 * email: daxing.yuan@yitu-inc.com
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
#include <queue>

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
using std::deque;
/*
  A[N] + A[k] > L
  sum+N-k-1 N=N-1, k
 */
class Solution
{
public:
    int triangleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int size = static_cast<int>(nums.size());
        int sum = 0;
        for (int k = size - 1; k >= 2; k--)
        {
            int end = k - 1, start = 0, big = nums[k];
            while (end > start)
            {
                if (nums[end] + nums[start] > big)
                {
                    sum += end - start;
                    end--;
                }
                else
                {
                    start++;
                }
            }
        }
        return sum;
    }
};

int main()
{
    vector<int> vec = {2,2,3,4};
    Solution s ;
    cout << s.triangleNumber(vec);
    return 0;
}
