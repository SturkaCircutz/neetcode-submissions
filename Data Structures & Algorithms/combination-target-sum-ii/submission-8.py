class Solution:
    def combinationSum2(self, nums: List[int], target: int) -> List[List[int]]:
        res, curr = [], []
        nums.sort()
        def dfs(curr, i, target):
            if target == 0:
                res.append(curr.copy())
                return
            if i == len(nums) or target < nums[i]:
                return
            curr.append(nums[i])
            dfs(curr, i+1, target-nums[i])
            while i <len(nums)-1 and nums[i] == nums[i+1]:
                i+=1
            curr.pop()
            dfs(curr, i+1, target)
        dfs(curr, 0, target)
        return res