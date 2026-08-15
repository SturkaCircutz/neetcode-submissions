class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        q = deque()
        fresh = 0
        def bfs(i, j):
            nonlocal fresh
            if i <0 or j <0 or i == row or j == col or grid[i][j] != 1:
                return False
            fresh -=1
            grid[i][j]+=1
            q.append([i, j])
            return True
            

        for i in range(row):
            for j in range(col):
                if grid[i][j] == 2:
                    q.append([i, j])
                if grid[i][j] == 1:
                    fresh+=1
        
        count = 0
        while q and fresh>0:
            for i in range(len(q)):
                [x, y] = q.popleft()
                bfs(x, y+1)
                bfs(x+1, y)
                bfs(x-1, y)
                bfs(x, y-1)
            count+=1
        return count if fresh==0 else -1
                