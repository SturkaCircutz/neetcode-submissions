class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        minheap = [(grid[0][0], 0, 0)]
        direct = [[0, 1], [1, 0], [-1, 0], [0, -1]]
        visit = set()
        while minheap:
            v, i, j = heapq.heappop(minheap)
            if i == len(grid) - 1 and j == len(grid) -1 :
                return v
            for nei in direct:
                ni = nei[0] + i 
                nj = nei[1] + j
                if ni < 0 or nj < 0 or ni >= len(grid) or nj >= len(grid[0]) or (ni, nj) in visit:
                    continue
                visit.add((ni, nj))
                heapq.heappush(minheap, (max(v, grid[ni][nj]), ni, nj))
        
