#include <vector>
using std::vector;

class Solution
{
public:
  vector<int> productExceptSelf(vector<int>& nums)
  {
    vector<int> ret(1, nums.size());
    int result = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
      ret[i] = result;
      result *= nums[i];
    }
    result = 1;
    for (int i = 0; i != nums.size(); i++)
    {
      ret[i] *= result;
      result *= nums[i];
    }
    return ret;
  }
};

int main(int argc, char *argv[])
{
  int array[] = {5,9,2,-9,-9,-7,-8,7,-9, 10};
  vector<int> ret(array, array + 10) ;
  Solution sol;
  sol.productExceptSelf(ret);
  return 0;
}
