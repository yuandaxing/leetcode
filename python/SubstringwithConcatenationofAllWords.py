class Solution:
    # @param S, a string
    # @param L, a list of string
    # @return a list of integer
    def init(self, index, start, count, L, dic) :
        curDict = {}
        for k in dic :
            curDict.setdefault(k, 0)
        for i in range(0, count) :
            cur = start + i * L
            if cur < len(index) and index[cur] != None :
                curDict[index[cur]] += 1
        return curDict
    def check(self, curDict, dic) :
        for k, v in curDict.iteritems():
            if dic[k] != v :
                return False
        return True
    def findSubstring(self, S, L):
        dic, LEN, count = {}, len(L[0]), len(L)
        for w in L :
            dic.setdefault(w, 0)
            dic[w] += 1
        index=[]
        for i in range(len(S)-LEN+1) :
            sub = S[i:i+LEN]
            index.append(sub if sub in dic else None)
        result = []
        for i in range(LEN) :
            cur = self.init(index, i, count, LEN, dic)
            left, right = None, None
            for j in range(i, len(index)-(count-1)*LEN, LEN) :
                if j > i :
                    left, right = index[j-LEN], index[j+(count-1)*LEN]
                if left : cur[left] -= 1
                if right : cur[right] += 1
                if self.check(cur, dic) :
                    result.append(j)
        return result
sol = Solution()
print sol.findSubstring("barfoothefoobarman", ["foo","bar"])
