class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l, r = 0, 0
        prefix = 0
        res = float('inf')
        while l < len(nums):
            if r == len(nums):
                l+=1
                r = l
                prefix = 0
                continue
            prefix += nums[r]
            if prefix >= target:
                print(prefix)
                res = min(res, r - l + 1)
                print(res)
                l += 1
                r = l
                prefix = 0
                continue
            r+=1
        return res if res != float('inf') else 0
