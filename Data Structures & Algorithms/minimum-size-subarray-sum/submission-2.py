class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l, r = 0, 0
        res = float('inf')
        prefix = 0
        while r < len(nums):
            prefix += nums[r]
            while prefix >= target:
                res = min(res, r - l +1)
                prefix-=nums[l]
                l+=1
            r+=1
        return res if res != float('inf') else 0
