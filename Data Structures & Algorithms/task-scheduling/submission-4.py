class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        tasks = Counter(tasks)
        tasks = [-t for t in tasks.values()]
        heapq.heapify(tasks)
        q = deque()
        time = 0
        while tasks or q:
            time +=1
            if tasks:
                curr = heapq.heappop(tasks) + 1
                if curr:
                    q.append((curr, time + n))
            if q and q[0][1] == time:
                heapq.heappush(tasks, q.popleft()[0])
        return time