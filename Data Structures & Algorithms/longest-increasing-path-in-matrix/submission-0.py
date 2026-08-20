class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        row, col = len(matrix), len(matrix[0])
        dp = {}
        def dfs(i, j, prev):
            if i >= row or j >= col or i < 0 or j < 0 or matrix[i][j] <= prev:
                return 0
            if (i, j) in dp:
                return dp[(i, j)]
            prev = matrix[i][j]
            res = 1
            res = max(res, 1+dfs(i+1, j, prev))
            res = max(res, 1+dfs(i-1, j, prev))
            res = max(res, 1+dfs(i, j+1, prev))
            res = max(res, 1+dfs(i, j-1, prev))
            dp[(i, j)] = res
            return res
        for i in range(row):
            for j in range(col):
                dfs(i, j, -1)
        return max(dp.values())