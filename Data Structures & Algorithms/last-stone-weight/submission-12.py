class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-s for s in stones]
        minheap = stones
        heapq.heapify(minheap)
        while len(minheap) > 1:
            first = heapq.heappop(minheap)
            sec = heapq.heappop(minheap)
            curr = first - sec
            heapq.heappush(minheap,curr)
        return abs(minheap[0])
        