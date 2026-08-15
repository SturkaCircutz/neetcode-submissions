class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        subset = []
        candidates.sort()
        def dfs(i, tar):
            if tar == 0:
                res.append(subset.copy())
                return
            if i >= len(candidates) or tar < 0:
                return
            subset.append(candidates[i])
            dfs(i+1, tar-candidates[i])
            while i < len(candidates)-1 and candidates[i] == candidates[i+1]:
                i+=1
            subset.pop()
            dfs(i+1, tar)
        dfs(0, target)
        return res