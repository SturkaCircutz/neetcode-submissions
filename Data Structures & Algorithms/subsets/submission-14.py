class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        curr = []
        res = []
        def dfs(i):
            res.append(curr.copy())
            for j in range(i, len(nums)):
                curr.append(nums[j])
                dfs(j+1)
                curr.pop()

        dfs(0)
        return res