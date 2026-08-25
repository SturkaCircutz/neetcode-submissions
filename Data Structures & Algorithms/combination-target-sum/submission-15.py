class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        curr = []
        nums.sort()
        def dfs(j, tar):
            if tar == 0:
                res.append(curr.copy())
                return
            if j == len(nums) or tar < nums[j]:
                return 
            curr.append(nums[j])
            dfs(j, tar - nums[j])
            curr.pop()
            dfs(j+1, tar)
        dfs(0, target)
        return res