class Solution:
    # @return a boolean
    def wildChar(self, s, i) :
        return (len(s)-i>1) and s[i+1]=='*'
    def isMatchA(self, s, si, p, pj) :
        if si >= len(s) or pj >= len(p) :
            return si >= len(s) and (pj >= len(p)
                                     or (self.wildChar(p, pj)
                                         and pj == len(p)-2))
        if self.wildChar(p, pj) :
            if self.isMatchA(s, si, p, pj+2) :
                return True
            else :
                return (p[pj]=='.' or p[pj] == s[si]) and self.isMatchA(s, si+1, p, pj)
        else :
            return (p[pj]=='.' or p[pj]==s[si]) and self.isMatchA(s, si+1, p, pj+1)
    def isMatch(self, s, p):
        return self.isMatchA(s, 0, p, 0)



        
#AC
class Solution1:
    # @return a boolean
    def wildChar(self, s, i) :
        return (len(s)-i>1) and s[i+1]=='*'
    def matchChar(self, s, p) :
        return p == '.' or s == p
    def isMatchA(self, s, si, p, pj) :
        if si >= len(s) or pj >= len(p) :
            return si >= len(s) and pj >= len(p)
        if self.wildChar(p, pj) :
            for i in range(0, len(s) - si+1) :
                cur = p[pj] if i == 0 else s[si+i-1]
                m = self.matchChar(cur, p[pj])
                if not m : break
                if self.isMatchA(s, si+i, p, pj+2) :
                    return True
            return False
        else :
            return (p[pj]=='.' or p[pj]==s[si]) and self.isMatchA(s, si+1, p, pj+1)
    def isMatch(self, s, p):
        p = self.preprocess(p)
        return self.isMatchA(s, 0, p, 0)
    def preprocess(self, p) :
        for i in range(len(p)) :
            if self.wildChar(p, i) and self.wildChar(p, i+2) and \
               self.matchChar(p[i], p[i+2]) :
                temp = '.*'
                if not '.' in [p[i], p[i+2]] :
                    temp = p[i] + '*'
                return self.preprocess(p[0:i]+temp + p[i+4:])
        return p
sol = Solution1()
# print sol.isMatch("aa","a")
# print sol.isMatch("aa","aa")
# print sol.isMatch("aaa","aa")
# print sol.isMatch("aa", "a*")
# print sol.isMatch("aa", ".*")
# print sol.isMatch("ab", ".*")
# print sol.isMatch("aab", "c*a*b")
print sol.isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c")
class Solution:
    # @return a boolean
    def wildChar(self, s, i) :
        return (len(s)-i>1) and s[i+1]=='*'
    def matchChar(self, s, p) :
        return p == '.' or s == p
    def isMatchA(self, s, si, p, pj) :
        if si >= len(s) or pj >= len(p) :
            return si >= len(s) and (pj >= len(p) or (self.wildChar(p, pj) and self.isMatchA(s, si, p, pj+2))) 
        if self.wildChar(p, pj) :
            for i in range(0, len(s) - si+1) :
                cur = p[pj] if i == 0 else s[si+i-1]
                m = self.matchChar(cur, p[pj])
                if not m : break
                if self.isMatchA(s, si+i, p, pj+2) :
                    return True
            return False
        else :
            return (p[pj]=='.' or p[pj]==s[si]) and self.isMatchA(s, si+1, p, pj+1)
    def isMatch(self, s, p):
        p = self.preprocess(p)
        return self.isMatchA(s, 0, p, 0)
    def preprocess(self, p) :
        for i in range(len(p)) :
            if self.wildChar(p, i) and self.wildChar(p, i+2) and \
               self.matchChar(p[i], p[i+2]) :
                temp = '.*'
                if not '.' in [p[i], p[i+2]] :
                    temp = p[i] + '*'
                return self.preprocess(p[0:i]+temp + p[i+4:])
        return p
