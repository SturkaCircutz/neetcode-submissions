class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        row, col = len(board), len(board[0])
        visit = set()
        def dfs(i, j, c):
            if c == len(word):
                return True
            if i < 0 or j < 0 or i >= row or j >= col or (i, j) in visit or board[i][j] != word[c]:
                return False
            visit.add((i, j))
            res = dfs(i+1, j, c+1) or dfs(i, j+1, c+1) or dfs(i-1, j, c+1) or dfs(i, j-1, c+1)
            visit.remove((i, j))
            return res
        for i in range(row):
            for j in range(col):
                if dfs(i, j, 0):
                    return True
        return False
        
