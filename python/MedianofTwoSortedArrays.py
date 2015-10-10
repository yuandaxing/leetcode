class Solution:
    # @return a float
    def findAK(self, A, B, k):
        left, right = -1, len(A)-1
        while left < right -1 :
            mid = left + (right - left) / 2
            p1 = k - mid - 1
            if p1 < 0 :
                right = mid
            elif p1 > len(B) :
                left = mid
            else :
                v = A[mid] if p1 == 0 else B[p1-1]
                if A[mid] >= v :
                    right = mid
                else :
                    left = mid
        p1 = k - right - 1
        if p1 < 0 or p1 > len(B) or right < 0 : return -1
        a1 = A[right] if p1 == 0 else B[p1-1]
        a2 = A[right] if p1 == len(B) else B[p1]
        return right if a1 <= A[right] <= a2 else -1
    def findK(self, A, B, k) :
        v = self.findAK(A, B, k)
        if v != -1 :
            return A[v]
        else :
            return B[self.findAK(B, A, k)]
    def findMedianSortedArrays(self, A, B):
        LEN = len(A) + len(B)
        if (LEN%2) :
            return self.findK(A, B, LEN / 2+1) * 1.0
        else :
            v = self.findK(A, B, LEN/2) * 1.0
            v2 = self.findK(A, B, LEN/2+1)
            return (v+v2)/2




sol = Solution()
a1 = [1,3,5,7,9]
a2 = [2,4,6,8,10]
print sol.findAK(a1, a2, 5)
print sol.findAK(a1, a2, 6)
print sol.findMedianSortedArrays([], [1])
print sol.findMedianSortedArrays([2], [])

print sol.findMedianSortedArrays([], [2,3])
