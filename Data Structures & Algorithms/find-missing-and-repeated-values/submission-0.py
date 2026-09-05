class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        visit = set()
        res = []
        for g in grid:
            for i in g:
                if i in visit:
                    res.append(i)
                visit.add(i)
        for i in range(n*n):
            if i+1 not in visit:
                res.append(i+1)
        return res
