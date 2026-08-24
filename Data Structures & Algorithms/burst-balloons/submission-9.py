class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        
        nums = [1] + nums + [1]
        mp = {}
        def dfs(l, r):
            if l > r:
                return 0
            if(l, r) in mp:
                return mp[(l,r)]
            mp[(l,r)] = 0
            for i in range(l, r+1):
                coin= nums[l-1] * nums[i] * nums[r+1]
                coin+=dfs(l, i-1)+dfs(i+1, r)
                mp[(l,r)] = max(coin, mp[(l,r)])
            return mp[(l,r)]
        return dfs(1, len(nums)-2)