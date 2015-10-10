class Solution:
    Max = 10000000
    def count(self, S) :
        d = {}
        for s in S:
            d.setdefault(s, 0)
            d[s] += 1
        return d
    # @return a string
    def minWindow(self, S, T):
        MinLen, s, cnt = Solution.Max, '', self.count(T)
        newS = T+S
        i, j, state = 0, len(T), dict(cnt)
        temp, i, state[T[0]] = newS[i], i+1, state[T[0]] - 1
        while j < len(newS) :
            while j < len(newS) and state[temp] < cnt[temp] :
                if newS[j] in state : state[newS[j]] += 1
                j += 1
            if state[temp] < cnt[temp] : break
            while i < j :
                if newS[i] in state :
                    if state[newS[i]] == cnt[newS[i]] :
                        break
                    else :
                        state[newS[i]] -= 1
                i += 1
            if i >= len(T) :
                val = j - i
                if val < MinLen :
                    MinLen,s= val + 1, newS[i:j]
            temp, state[newS[i]] = newS[i], state[newS[i]]-1
            i += 1
        return s
