class Solution:
    # @param s, a string
    # @return a boolean
    def isInteger(self, s) :
        return s.isdigit()
    def isSignInteger(self, s):
        return s!='' and s[0] in ['+', '-'] and self.isInteger(s[1:])
    def validInteger(self, s) :
        return self.isInteger(s) or self.isSignInteger(s)
    def isPointNumber(self, s) :
        v = s.split('.')
        return len(v) == 2 and (v[0] != '' or v[1] != '') and  \
            (v[1] == '' or self.isInteger(v[1])) and \
            (v[0] == '' or self.isInteger(v[0]))
    def isSignPointNumber(self, s) :
        return s != '' and s[0] in ['+', '-'] and self.isPointNumber(s[1:])
    def validPointNumber(self, s) :
        return self.isPointNumber(s) or self.isSignPointNumber(s)
    def validNumber(self, s) :
        return self.validInteger(s) or self.validPointNumber(s)
    def isNumber(self, s):
        v = s.strip().split('e')
        eNum = '' if len(v) < 2 else v[1]
        return len(v) <= 2 and (self.validNumber(v[0]) and (self.validInteger(eNum) if 'e' in s else True))


sol = Solution()
print sol.isNumber('0')
print sol.isNumber(' 0.1')
print sol.isNumber('abc')
print sol.isNumber('1 a')
print sol.isNumber('2e10')
print sol.isNumber('0e')
