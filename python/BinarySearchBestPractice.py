#Find Minimum in Rotated Sorted Array 
class Solution:
    def findMin(self, num):
        left, right = 0, len(num)-1
        if num[right] > num[left] : return num[left]
        while left < right-1 :
            mid = left + (right - left)/2
            if num[mid] > num[left] :
                left = mid
            else :
                right = mid
        return num[right]
    def findMinV2(self, num) :
        left, right = 0, len(num)-1
        while left < right-1 :
            mid = left + (right - left)/2
            if num[mid] < num[right] :
                right = mid
            else :
                left = mid
        return min(num[left], num[right])

#loop-invariant left < minidx <= right.
#
#1.Intial.left = -1,right = num - 1.the loop-invariant keeps evidently. 
#2.Keeping
#let's check only the first condition branch:
#if num[mid] < num[right],right = mid
#	After this branch done, the left is not change, so we only need to preserve that minidx <= right or minidx <= mid. 
#	Because the minium of the array is smaller than any elements of the array,we know that minium <= num[mid]. but this doesn't mean that minidx <= mid., then all elements in A[mid:right] is ascending, than we can get minidx <= mid.
#to get this condition,let's check the property of the problem.you may find that the sub array A[minidx:right] and A[left:minidx-1] is ascending if "left < minidx <=right" holds. What we need now is just "min < mid <= right". It's not hard to find that A[left] > A[right] when "left < minidx <= right" holds,so all elements in A[left:minidx-1] is larger than A[right].Then the mid can't be in [left:minidx-1],it must be in (minidx,right].
#the analysis of the second condition branch is similar.
#3.Terminate 
#for left < right -1, we can get the follows: 
#mid = [(right + left )/2] > [(left + 1 + left )/2] = left
#mid = [(left + right)/2] < [(right + 1 + right)/2] = right
#so  left < mid < right.
#at each time, mid is assigned to either left or right.So the (left,right] is reduced at each iteration. After finite step, we have right - left = 1 and the loop exits.
#4.Postcondition
#we have shown that when the loop exits the loop-invariant left < minidx <= right keeps and right - left = 1.so the mindix can only be right which means min = num[right]

#a more comprehensive proof is to use three loop-invariants
#1.left < minidx <= right.
#2.A[left:minidx -1] and A[minidx:right] are ascending
#3.A[left] > A[right]
#
    def findMinV3(self, num) :
        left, right = -1, len(num)-1
        # set num[-1] to be the magic value. min in (left,...,right], num[left] > num[right], [left, min-1] and [min, right] are asc
        while left < right-1 :
            # min in (left,...,right], num[left] > num[right], [left, min-1] and [min, right] are asc
            mid = left + (right - left)/2
            # left < mid < right, so this loop will be terminated.
            if num[mid] < num[right] :
                right = mid
                # min in (left,...,right], num[left] > num[right], [left, min-1] and [min, right] are asc
                # min <= mid
            else :
                left = mid
                # min in (left,...,right], num[left] > num[right], [left, min-1] and [min, right] are asc
                # mid < min

        # left = right - 1, min in (left,...,right], num[left] > num[right], [left, min-1] and [min, right] are asc
        return num[right]

#Find Minimum in Rotated Sorted Array II
#allow duplicate
class Solution2:
     def findMin(self, num) :
         left, right = 0, len(num)-1 
         if num[right] > num[left] : return num[left]
         while left < right-1:
             mid = left + (right - left)/2
             if  num[mid] > num[right] :
                 left = mid
             elif num[mid] < num[right] :
                 right = mid
             else :
                 right -= 1
         return num[right]
    # this method will be O(n) if all the values are the same.
    def findMinV2(self, num)
         left, right = -1, len(num)-1 
         while left < right-1:
             mid = left + (right - left)/2
             if  num[mid] > num[right] :
                 left = mid
             elif num[mid] < num[right] :
                 right = mid
             else :
                 right -= 1
         return num[right]

    def findMinV3(self, num):
        left, right = -1, len(num)-1 
        # set num[-1] to be the magic value. min in (left,...,right], num[left] >= num[right], [left, min-1] and [min, right] are non-desc
        while left < right-1:
            # min in (left,...,right], num[left] >= num[right], [left, min-1] and [min, right] are non-desc
            mid = (left+right)/2
            if  num[mid] > num[right] :
                # mid must in [left, min-1], so mid < min
                left = mid
                # min in (left,...,right], num[left] >= num[right], [left, min-1] and [min, right] are non-desc
            elif num[mid] < num[right] :
                # mid must in [min, right], so min <= mid
                right = mid
                # min in (left,...,right], num[left] >= num[right], [left, min-1] and [min, right] are non-desc
            elif num[mid] == num[right]:
                # mid must in [min, right], so min <= mid
                right = mid
        return num[right]

#Search Insert Position
# @param A, a list of integers
# @param target, an integer to be inserted
# @return integer
class Solution3:
     def searchInsert(self, A, target):
         left, right = -1, len(A) 
         while left < right-1:
             mid = left + (right - left)/2
             if A[mid] < target :
                 left = mid
             else :
                 right = mid
         return right

#Search in Rotated Sorted Array
# @param A, a list of integers
# @param target, an integer to be searched
# @return an integer
class Solution4:
    def search(self, A, target):
        left, right = 0, len(A)-1
        while left < right-1 :
            mid = left + (right - left)/2
            if A[mid] > A[left] :
                if A[mid] >= target >= A[left] :
                    right = mid
                else :
                    left = mid
            else :
                if A[right] >= target >= A[mid]:
                    left = mid
                else :
                    right = mid
        if A[left] == target : return left
        if A[right] == target : return right
        return -1
    def searchV2(self, A, target):
        left, right = -1, len(A)-1
        while left < right-1 :
            mid = left + (right - left)/2
            if A[mid] > A[right] :
                if A[mid] < target or target <= A[right] :
                    left = mid
                else : right = mid
            else :
                if A[right] >= target > A[mid]:
                    left = mid
                else : right = mid
        return right if A[right] == target else -1



#Search in Rotated Sorted Array II 
# @param A a list of integers
# @param target an integer
# @return a boolean
class Solution5:
    def search(self, A, target):
        left, right = 0, len(A)-1
        while left < right-1 :
            mid = left + (right - left)/2
            if A[mid] > A[right] :
                if A[mid] >= target >= A[left] :
                    right = mid
                else :
                    left = mid
            elif A[mid] < A[right]
                if A[right] >= target >= A[mid]:
                    left = mid
                else :
                    right = mid
            else :
                right -= 1
        if A[left] == target : return True
        if A[right] == target : return True
        return False

    def searchV2(self, A, target):
        left, right = -1, len(A)-1
        while left < right-1 :
            mid = left + (right - left)/2
            if A[mid] > A[right] :
                if A[mid] < target or target <= A[right] :
                    left = mid
                else : right = mid
            elif A[mid] < A[right] :
                if A[right] >= target > A[mid]:
                    left = mid
                else : right = mid
            else :
                right -= 1
        return A[right] == target
