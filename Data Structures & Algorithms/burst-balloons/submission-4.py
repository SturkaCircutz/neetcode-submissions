class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        dp = {}
        nums = [1] + nums + [1]
        def dfs(i, j):
            if i > j:
                return 0
            if (i, j) in dp:
                return dp[(i, j)]
            dp[(i, j)] = 0
            for m in range(i, j+1):
                coin = nums[i-1] * nums[m] * nums[j+1] 
                coin += dfs(i, m-1) + dfs(m+1, j)
                dp[(i, j)] = max(coin, dp[(i, j)])
            return dp[(i, j)]
        return dfs(1, len(nums)-2)
              