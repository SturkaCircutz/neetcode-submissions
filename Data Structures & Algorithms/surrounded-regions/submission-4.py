class Solution:
    def solve(self, board: List[List[str]]) -> None:
        row, col = len(board), len(board[0])
        def dfs(i, j):
            if i < 0 or j < 0 or i >=row or j >=col or board[i][j] != 'O':
                return
            board[i][j] = 'F'
            dfs(i+1, j)
            dfs(i-1, j)
            dfs(i, j+1)
            dfs(i, j-1)
        for j in range(col):
            if board[row-1][j] == 'O':
                dfs(row-1, j)
            if  board[0][j] == 'O':
                dfs(0, j)
        for j in range(row):
            if board[j][col-1] == 'O':
                dfs(j, col-1)
            if  board[j][0] == 'O':
                dfs(j, 0)
            
        for i in range(row):
            for j in range(col):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
        for i in range(row):
            for j in range(col):
                if board[i][j] == 'F':
                    board[i][j] = 'O'
        
        