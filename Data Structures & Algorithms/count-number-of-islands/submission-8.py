class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        row, col = len(grid), len(grid[0])
        count = 0
        def dfs(i, j):
            if i >= row or j >= col or i < 0 or j < 0 or grid[i][j] != '1':
                return
            grid[i][j]='#'
            dfs(i+1, j)
            dfs(i-1, j)
            dfs(i, j+1)
            dfs(i, j-1)
        for i in range(row):
            for j in range(col):
                if grid[i][j] == '1':
                    dfs(i, j)
                    count+=1
        return count
