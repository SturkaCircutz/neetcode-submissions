class Solution:
    def solve(self, board: List[List[str]]) -> None:
        row, col = len(board), len(board[0])
        def dfs(i, j):
            if i >= row or j >= col or i < 0 or j < 0 or board[i][j]!='O':
                return
            board[i][j]='#'
            dfs(i+1, j)
            dfs(i-1, j)
            dfs(i, j+1)
            dfs(i, j-1)
        for i in range((row)):
            for j in range((col)):
                if (i in [0, row-1] or j in [0, col-1]) and board[i][j]=='O':
                    dfs(i, j)
        for i in range((row)):
            for j in range((col)):
                if board[i][j]=='O':
                    board[i][j]='X'
        for i in range((row)):
            for j in range((col)):
                if board[i][j]=='#':
                    board[i][j]='O'

        