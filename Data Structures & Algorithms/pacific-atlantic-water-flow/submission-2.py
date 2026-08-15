class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        direct = [[1, 0], [0, 1], [-1, 0], [0, -1]]
        row, col = len(heights), len(heights[0])
        pac, atl = set(), set()
        def dfs(r, c, sea):
            sea.add((r,c))
            for d in direct:
                nr = d[0] + r
                nc = d[1] + c
                if nr<0 or nc<0 or nr==row or nc == col or heights[nr][nc] < heights[r][c] or (nr, nc) in sea:
                    continue
                dfs(nr, nc, sea)
            
        res = [] 
        for i in range(row):
            dfs(i, col-1, atl)
            dfs(i, 0, pac)
        for i in range(col):
            dfs(row-1, i, atl)
            dfs(0, i, pac)
        
        for i in range(row):
            for j in range(col):
                if (i, j) in pac and (i, j) in atl:
                    res.append([i, j])
        return res
        
        