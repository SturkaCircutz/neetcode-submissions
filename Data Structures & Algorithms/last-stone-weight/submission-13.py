class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        minheap = []
        for i in stones:
            heapq.heappush(minheap, -i)
        while len(minheap) > 1:
            item1 = heapq.heappop(minheap)
            item2 = heapq.heappop(minheap)
            heapq.heappush(minheap, -abs(item1 - item2))
        
        return -minheap[0]  