class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        pre = {i : [] for i in range(n)}
        for i in range(n):
            x1, y1 = points[i]
            for j in range(i+1, n):
                x2, y2 = points[j]
                dis = abs(x1 - x2) + abs(y1 - y2)
                pre[i].append((j, dis))
                pre[j].append((i, dis))
        visit =set()
        minheap = [[0, 0]]
        total = 0
        while len(visit) < n:
            currdis, curr = heapq.heappop(minheap)
            if curr in visit:
                continue
            visit.add(curr)
            total += currdis
            for nei, neidis in pre[curr]:
                heapq.heappush(minheap, [neidis, nei])
        return total

            
