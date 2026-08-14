class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        curr = []
        def dfs(i, curr, tar):
            if i >= len(nums) or tar < 0:
                return
            if tar == 0:
                res.append(curr.copy())
                return
            curr.append(nums[i])
            dfs(i, curr, tar-nums[i])
            curr.pop()
            dfs(i+1, curr, tar)

        dfs(0, curr, target)
        return res