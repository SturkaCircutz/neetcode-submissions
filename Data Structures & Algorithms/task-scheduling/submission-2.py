class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        count = Counter(tasks)
        maxheap = [-c for c in count.values()]
        heapq.heapify(maxheap)
        q = deque()
        time = 0
        while maxheap or q:
            time+=1
            if maxheap:
                cnt = heapq.heappop(maxheap)+1
                if cnt:
                    q.append([cnt, n+time])
            if q and q[0][1] == time:
                heapq.heappush(maxheap, q.popleft()[0])
        return time
        