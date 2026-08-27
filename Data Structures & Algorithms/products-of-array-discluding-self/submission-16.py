class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        sums = [1] *len(nums)
        for i in range(1, len(nums)):
            sums[i] = sums[i-1]*nums[i-1]
        prefix = 1
        for j in range(len(nums)-2, -1, -1):
            prefix *= nums[j+1]
            sums[j] *= prefix
        return sums