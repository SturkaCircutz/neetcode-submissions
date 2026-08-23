class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        mp = {}
        def dfs(i, j, prev):
            if i < 0 or j < 0 or i >= len(matrix) or j >= len(matrix[0]) or matrix[i][j] <= prev:
                return 0
            if (i, j) in mp:
                return mp[(i, j)]
            prev = matrix[i][j]
            res = 1
            res = max(res, 1+dfs(i+1, j, prev))
            res = max(res, 1+dfs(i-1, j, prev))
            res = max(res, 1+dfs(i, j+1, prev))
            res = max(res, 1+dfs(i, j-1, prev))
            mp[(i, j)] = res
            return res
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                dfs(i,j,-1)
        return max(mp.values())