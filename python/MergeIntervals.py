# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    # @param intervals, a list of Interval
    # @return a list of Interval
    def merge(self, intervals):
        intervals.sort(key=lambda e:e.start)
        i = 0
        while i < len(intervals) - 1 :
            cur, next1 = intervals[i], intervals[i+1]
            if cur.start <= next1.start <= cur.end :
                cur = intervals.pop(i)
                next1 = intervals.pop(i)
                newI = Interval(min(cur.start, next1.start), max(cur.end, next1.end))
                intervals.insert(i, newI)
            else :
                i+= 1
        return intervals
