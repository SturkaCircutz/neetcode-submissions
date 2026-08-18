class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[-1]
        if len(nums) == 2:
            return max(nums)
        def helper(i, j):
            dp = [0] * (j+1)
            dp[i] = nums[i]
            dp[i+1] = max(nums[i], nums[i+1])
            for x in range(i+2, j):
                dp[x] = max(dp[x-1], dp[x-2]+nums[x])
            return dp[j-1]
        n = len(nums)
        return max(helper(1, n), helper(0, n-1))
            