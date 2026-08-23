class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mp = {}
        minheap = []
        res = []
        for n in nums:
            mp[n] = 1 + mp.get(n, 0)
        for i in mp:
            heapq.heappush(minheap, (mp[i], i))
            if len(minheap) > k:
                heapq.heappop(minheap)
        for i in range(k):
            res.append(minheap[i][1])
        return res


