class Solution:
    def numDecodings(self, s: str) -> int:
        dp = {}
        dp[len(s)] = 1
        for j in range(len(s)-1, -1, -1):
            if j in dp:
                return dp[j]
            if s[j] == '0':
                dp[j] = 0
                continue
            dp[j] = dp[j+1]
            if j <= len(s)-2 and (s[j] == '1' or (s[j] == '2' and s[j+1] in '0123456')):
                dp[j] += dp[j+2]
        return dp[0]
        
             
            