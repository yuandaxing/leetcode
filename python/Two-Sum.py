class Solution(object):
    '''
    two sums
    '''
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        nums_idx = [[v, idx+1] for idx, v in enumerate(nums)]
        nums_idx.sort(key = lambda e: e[0])

        left, right = 0, len(nums_idx) - 1
        result = []
        while left < right:
            sum = nums_idx[left][0] + nums_idx[right][0]
            if sum > target:
                right -= 1
            elif sum < target:
                left += 1
            else:
                result = [nums_idx[left][1], nums_idx[right][1]]
                break
        result.sort()
        return result

test = [3,2,4]
print Solution().twoSum(test, 6)
