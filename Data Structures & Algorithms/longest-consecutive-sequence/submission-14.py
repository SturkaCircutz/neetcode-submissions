class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums.sort()
        res, count = 0, 1
        mp = Counter(nums)
        for i in mp:
            if i + 1 in mp:
                count +=1
            else:
                res = max(count, res)
                count = 1
        return res