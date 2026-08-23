class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        minheap = []
        mp = Counter(nums)
        res = []
        for i in mp:
            heapq.heappush(minheap, (mp[i], i))
            if len(minheap) > k:
                heapq.heappop(minheap)
        for i in range(k):
            res.append(minheap[i][1])
        return res
            