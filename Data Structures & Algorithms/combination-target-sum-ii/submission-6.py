class Solution:
    def combinationSum2(self, nums: List[int], target: int) -> List[List[int]]:
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
            dfs(j+1, tar - nums[j])
            while j < len(nums)-1 and nums[j] == nums[j+1]:
                j+=1
            curr.pop()
            dfs(j+1, tar)
        dfs(0, target)
        return res