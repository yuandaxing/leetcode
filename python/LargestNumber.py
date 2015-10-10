class Solution:
    # @param num, a list of integers
    # @return a string
    def compare(self, x, y) :
        left, right = x+y, y+x
        if left < right :
            return 1
        elif left > right :
            return -1
        else :
            return 0

    def largestNumber(self, num):
        num = [str(x) for x in num]
        num.sort(cmp = self.compare)
        return ''.join(num)

sol = Solution()
print sol.largestNumber([3, 30, 34, 5, 9])
