class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res , curr = [], []
        def dfs(i, curr):
            res.append(curr.copy())
            if i == len(nums):
                return
            for j in range(i, len(nums)):
                curr.append(nums[j])
                dfs(j+1, curr)
                curr.pop()
        dfs(0, curr)
        return res
