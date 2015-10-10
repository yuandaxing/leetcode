class Solution:
    # @param dungeon, a list of lists of integers
    # @return a integer
    def __init__(self):
        self.minV = 0
    def initMinV(self, dungeon) :
        self.minV, pathV = dungeon[0][0], 0
        for i in range(len(dungeon)) :
            pathV += dungeon[i][0]
            if pathV < self.minV :
                self.minV = pathV
        for j in range(1, len(dungeon[0])) :
            pathV += dungeon[len(dungeon)-1][j]
            if pathV < self.minV :
                self.minV = pathV

    def searchMinHP(self, dungeon, pos, cur, mV) :
        maxR, maxC = len(dungeon), len(dungeon[0])
        if pos[0] >= maxR or pos[1] >= maxC :
            return
        cur += dungeon[pos[0]][pos[1]]
        mV = mV if cur >= mV else cur

        if mV < self.minV : return
        if pos[0] == maxR - 1 and pos[1] == maxC - 1 :
            self.minV = mV
            return

        for inc in [[0, 1], [1, 0]] :
            self.searchMinHP(dungeon, [pos[0]+inc[0], pos[1]+inc[1]], cur, mV)

    def calculateMinimumHP(self, dungeon):
        self.initMinV(dungeon)
        self.searchMinHP(dungeon, [0, 0], 0, 0)
        return (-self.minV) + 1


sol = Solution()
board = [[-2, -3, 3], [-5, -10, 1], [10, 30, -5]]
print sol.calculateMinimumHP(board)
