class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        neighbors = {i : [] for i in range(1,n+1)}
        edges = [float('inf')] * (n+1)
        edges[k] = 0
        visit = set()
        for i in range(len(times)):
            neighbors[times[i][0]].append((times[i][2], times[i][1]))
        minheap = []
        minheap.append((0, k))
        while minheap:
            currv, curr = heapq.heappop(minheap)
            visit.add(curr)
            for i in neighbors[curr]:
                neiv, nei = i
                if neiv+edges[curr] < edges[nei] and nei not in visit:
                    edges[nei] = edges[curr] + neiv
                    heapq.heappush(minheap, (neiv+edges[curr], nei))
            if len(visit) == n:
                return currv
        return -1
            


 
