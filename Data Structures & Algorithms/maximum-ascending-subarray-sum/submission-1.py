class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        res = msum = nums[0]
        for i in range(1, len(nums)):
            if nums[i] > nums[i-1]:
                msum += nums[i]
                res = max(res, msum)
            else:
                msum = nums[i]
        return res