class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        row, col = len(grid), len(grid[0])
        count = 0
        visit = set()
        q = deque()
        def more(i, j):
            if i < 0 or j < 0 or i >= row or j >= col or grid[i][j] ==-1 or (i, j) in visit:
                return
            q.append((i, j))
            visit.add((i, j))
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 0:
                    visit.add((i, j))
                    q.append((i, j))
        while q:
            for m in range(len(q)):
                i, j = q.popleft()
                grid[i][j] = count
                more(i+1, j)
                more(i-1, j)
                more(i, j+1)
                more(i, j-1)
            count +=1
