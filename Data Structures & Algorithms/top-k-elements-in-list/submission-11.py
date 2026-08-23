class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        buc = [[] for i in range(len(nums)+1)]
        res = []
        heap = Counter(nums)
        for m, v in heap.items():
            buc[v].append(m)
        for i in range(len(buc)-1, 0, -1):
            while buc[i] and k > 0:
                curr = buc[i].pop()
                res.append(curr)
                k-=1
        return res
            
