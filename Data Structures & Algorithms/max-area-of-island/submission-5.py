class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        res = 0
        def dfs(i, j):
            if i < 0 or j < 0 or i == row or j == col or grid[i][j] != 1:
                return 0
            grid[i][j] = 2
            return 1 +dfs(i+1, j)+ dfs(i-1, j)+ dfs(i, j+1)+ dfs(i, j-1)
        for i in range(row):
            for j in range(col):
                res = max(dfs(i, j), res)
        return res
        
