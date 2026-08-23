class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        mp = Counter(nums)
        res = 0
        count = 1
        for i in sorted(mp):
            if i+1 in mp:
                count +=1
                continue
            res = max(count, res)
            count = 1
        return res
                
