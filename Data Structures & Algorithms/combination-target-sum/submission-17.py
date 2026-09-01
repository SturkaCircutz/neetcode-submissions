class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res, curr = [], []
        nums.sort()
        def backtrack(i, curr, target):
            if target == 0:
                res.append(curr.copy())
                return
            for j in range(i, len(nums)):
                if target - nums[j] < 0:
                    break
                curr.append(nums[j])
                backtrack(j, curr, target - nums[j])
                curr.pop()
        backtrack(0, curr, target)
        return res