class Solution:
    def partition(self, nums: str) -> List[List[str]]:
        curr, res = [], []
        def ispali(i, j):
            while i < j:
                if nums[i] != nums[j]:
                    return False
                i+=1
                j-=1
            return True
        def dfs(i):
            if i == len(nums):
                res.append(curr.copy())
                return
            for j in range(i, len(nums)):
                if ispali(i, j):
                    curr.append(nums[i:j+1])
                    dfs(j+1)
                    curr.pop()
            
        dfs(0)
        return res