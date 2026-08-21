class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        cache = {}
        def dfs(i, j):
            if  j == amount:
                return 1
            if j > amount:
                return 0 
            if i == len(coins):
                return 0
            if (i, j) in cache:
                return cache[(i, j)]
            cache[(i, j)] = dfs(i, j+coins[i]) + dfs(i+1, j)
            return cache[(i, j)]
        return dfs(0, 0)