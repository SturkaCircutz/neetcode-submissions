class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        buc = [[] for i in range(len(nums)+1)]
        count = {}
        for n in nums:
            count[n]=1+count.get(n, 0)
        for ke,v in count.items():
            buc[v].append(ke)
        res = []
        for i in range(len(buc)-1, 0, -1):
            for j in buc[i]:
                res.append(j)
                if len(res) == k:
                    return res