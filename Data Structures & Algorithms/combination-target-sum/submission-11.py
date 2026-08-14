class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        curr = []
        nums.sort()
        def dfs(j, tar):
            if tar == 0:
                res.append(curr.copy())
                return
            for i in range(j, len(nums)):
                if nums[i] > tar:
                    break

                curr.append(nums[i])
                dfs(i, tar-nums[i])
                curr.pop()
        dfs(0, target)
        return res

