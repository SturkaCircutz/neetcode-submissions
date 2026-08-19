class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        curmin, curmax = 1, 1
        res = max(nums)
        for i in range(len(nums)):
            if nums[i] == 0:
                curmin, curmax = 1,1
                continue
            tmp = curmax
            curmax = max(curmax* nums[i], curmin * nums[i], nums[i])
            curmin = min(tmp* nums[i], curmin * nums[i], nums[i])
            res = max(res, curmax)
        return res