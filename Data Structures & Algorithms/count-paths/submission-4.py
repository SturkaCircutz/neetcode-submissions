class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [0 for i in range(n+1)]
        dp[n-1] = 1
        newdp = dp
        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                newdp[j] += dp[j+1]
            dp = newdp
        return dp[0]

