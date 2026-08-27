class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        minheap = []
        mp = Counter(nums)
        for key, value in mp.items():
            heapq.heappush(minheap, (value, key))
            if len(minheap) > k:
                heapq.heappop(minheap)
        res = []
        for i in minheap:
            res.append(i[1])
        return res