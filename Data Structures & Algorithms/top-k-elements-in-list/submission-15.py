class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        m = len(nums)
        bucket = {i : [] for i in range(m+1)}
        freq = Counter(nums)
        for key, v in freq.items():
            bucket[v].append(key)
        res = []
        for i in range(len(bucket)-1, -1, -1):
            while bucket[i] and k > 0:
                print(k)
                res.append(bucket[i].pop())
                k-=1
            
        return res