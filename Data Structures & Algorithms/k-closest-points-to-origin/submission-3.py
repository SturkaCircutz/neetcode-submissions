class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        minheap = []
        res = []
        for p in points:
            dis = p[0]*p[0] + p[1]*p[1]
            heapq.heappush(minheap, (dis, p))
        while k > 0:
            res.append(heapq.heappop(minheap)[1])
            k-=1
        return res