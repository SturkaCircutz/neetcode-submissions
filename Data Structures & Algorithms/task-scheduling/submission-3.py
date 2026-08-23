class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        mp = Counter(tasks)
        maxheap = [-t for t in mp.values()]
        heapq.heapify(maxheap)
        time = 0
        q = deque()
        while maxheap or q:
            time +=1
            if maxheap:
                curr = heapq.heappop(maxheap)+1
                if curr:
                    q.append((curr, time + n))
            if q and q[0][1] == time:
                heapq.heappush(maxheap, q.popleft()[0])
        return time
