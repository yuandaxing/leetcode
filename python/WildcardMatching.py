#http://yucoding.blogspot.com/2013/02/leetcode-question-123-wildcard-matching.html
class Solution:
    # @param s, an input string
    # @param p, a pattern string
    # @return a boolean
    #DP F[i][j] = F[i][j-1] if j-1=='*', F[i-1][j-1] if s[i] == p[j]
    #or F[i-1][j] if p[j]=='*'
    def DP(self, s, p) :
        F = [[False for i in p] for j in range(2)]
        for i in range(len(s)) :
            F[0], F[1] = F[1], [False for k in p]
            for j in range(len(p)) :
                Fij_1, Fi_1j_1, Fi_1j = False, False, False
                if p[j] == '*' :
                    Fij_1 = False if j-1 < 0 else F[1][j-1]
                    Fi_1j = False if i-1 < 0 else F[0][j]
                if p[j] == '?' or p[j] == '*' or p[j] == s[i] :
                    if i - 1 < 0 and j - 1 < 0 :
                        Fi_1j_1 = True
                    elif i - 1 < 0 or j - 1 < 0 :
                        Fi_1j_1 = False
                    else :
                        Fi_1j_1 = F[0][j-1]
                if True in [Fij_1, Fi_1j_1, Fi_1j] :
                    F[1][j] = True
        if s == '' or p == '' :
            return s == '' and (p=='' or p == '*')
        return F[1][len(p)-1]

    def isMatch(self, s, p):
        p = self.preprocess(p)
        return self.DP(s, p)
    def preprocess(self, p) :
        for i in range(len(p)-1) :
            if p[i] == '*' and p[i+1] == '*' :
                   return self.preprocess(p[0:i]+'*'+p[i+2:])
        return p



sol = Solution()
print sol.isMatch("aaaaaaabbbbbabbaabaaa", "b**aba")
