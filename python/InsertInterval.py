class Solution:
    # @param intervals, a list of Intervals
    # @param newInterval, a Interval
    # @return a list of Interval
    def insertBig(self, intervals, newInterval) :
        left, right = -1, len(intervals)
        while left < right - 1 :
            mid = left + (right - left) / 2
            if intervals[mid].start >= newInterval.start :
                right = mid
            else :
                left = mid
        intervals.insert(right, newInterval)
        return right
    def splice(self, intervals, i) :
        while i < len(intervals) - 1 :
            cur, next1 = intervals[i], intervals[i+1]
            if cur.start <= next1.start <= cur.end :
                cur = intervals.pop(i)
                next1 = intervals.pop(i)
                newI = Interval(min(cur.start, next1.start), max(cur.end, next1.end))
                intervals.insert(i, newI)
            else :
                break
    def insert(self, intervals, newInterval):
        pos = self.insertBig(intervals, newInterval)
        if pos > 0 :
            self.splice(intervals, pos-1)
        self.splice(intervals, pos)
        return intervals
