class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        curr = []
        nums.sort()
        def dfs(i, tar):
            if tar == 0:
                res.append(curr.copy())
                return
            for j in range(i, len(nums)):
                if tar < nums[j]:
                    return 
                curr.append(nums[j])
                dfs(j, tar - nums[j])
                curr.pop()
        dfs(0, target)
        return res