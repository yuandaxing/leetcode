class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return a list of length 2, [index1, index2]
    def searchRange(self, A, target):
        left, right=0, len(A)
        while left < right -1 :
            mid = left + (right-left) / 2
            if A[mid] <= target :
                left = mid
            else :
                right = mid
        if A[left] != target :
            return [-1, -1]
        start = left
        while start >= 0 and A[start] == target :
            start -= 1
        return [start+1, left]
