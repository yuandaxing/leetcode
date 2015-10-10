class Solution:
    # @return a list of lists of string
    def __init__(self) :
        self.result = []
    def place(self, postion, i, j) :
        a, b, c = i+j, i-j, j
        for p in postion :
            if a == (p[0]+p[1]) or b == (p[0] - p[1]) \
               or c == p[1] :
                return False
        return True
    def solveNQueensAux(self, board, position, i) :
        if i == len(board[0]) :
            cur = [''.join(board[i]) for i in range(len(board[0]))]
            self.result.append(cur)
            return 

        for j in range(len(board[0])) :
            if self.place(position, i, j) :
                board[i][j] = 'Q' 
                position.append([i,j])
                self.solveNQueensAux( board, position, i+1) 
                board[i][j] = '.'
                position.pop()
    def solveNQueens(self, n):	
        board = [['.'] * n for i in range(n)]
        self.solveNQueensAux(board, [], 0)
        return self.result


sol = Solution()
print sol.solveNQueens(4)
