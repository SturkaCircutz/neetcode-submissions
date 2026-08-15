class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        def dfs(i, j):
            if i >= row or j >= col or i < 0 or j < 0 or grid[i][j]!=1:
                return 0
            grid[i][j]=2
            return 1+dfs(i+1, j)+dfs(i, j+1)+dfs(i, j-1)+dfs(i-1, j)
        maxi = 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    maxi = max(maxi, dfs(i, j))
        return maxi