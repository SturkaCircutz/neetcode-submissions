class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:

        prev = 2
        res, count = 0, 0
        for i in nums:
            if i == prev and i == 1:
                count +=1
            elif i == 1:
                res = max(count, res)
                count = 1
            prev = i
        res = max(count, res)
        return res