class Twitter:

    def __init__(self):
        self.count = 0
        self.followmp = defaultdict(set)
        self.tweetmp = defaultdict(list)

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.tweetmp[userId].append([self.count, tweetId])
        self.count -= 1

    def getNewsFeed(self, userId: int) -> List[int]:
        res = []
        minheap = []
        self.followmp[userId].add(userId)
        for i in self.followmp[userId]:
            if i in self.tweetmp:
                idx = len(self.tweetmp[i])-1
                count, tweetid = self.tweetmp[i][idx]
                heapq.heappush(minheap, [count, tweetid, i, idx-1])
        heapq.heapify(minheap)
        while minheap and len(res) < 10:
            curr = heapq.heappop(minheap)
            count, tweetid, userId, idx = curr
            res.append(tweetid)
            if idx >= 0:
                count, tweetid = self.tweetmp[userId][idx]
                heapq.heappush(minheap, [count, tweetid, userId, idx-1])
        return res
            

    def follow(self, followerId: int, followeeId: int) -> None:
        self.followmp[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.followmp[followerId]:
            self.followmp[followerId].remove(followeeId)
