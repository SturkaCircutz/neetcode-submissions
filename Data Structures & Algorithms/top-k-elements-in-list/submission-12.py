class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        minheap = []
        res = []
        mp = Counter(nums)
        for key, v in mp.items():
            heapq.heappush(minheap, (v, key))
            if len(minheap) > k:
                heapq.heappop(minheap)
        for i in minheap:
            res.append(i[1])
        return res
            