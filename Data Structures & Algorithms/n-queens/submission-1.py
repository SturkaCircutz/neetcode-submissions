class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        col = set()
        negDiag = set()
        posDiag = set()
        res = [["."] * n for i in range(n)]
        ans = []
        def backtrack(r):
            
            if r == n:
                copy = ["".join(row) for row  in res]
                ans.append(copy)
                return
            for c in range(n):
                if  c in col or (r-c) in negDiag or (r+c) in posDiag:
                    continue
                col.add(c)
                negDiag.add(r-c)
                posDiag.add(r+c)
                res[r][c] = 'Q'
                backtrack(r+1)

                col.remove(c)
                negDiag.remove(r - c)
                posDiag.remove(r+c)
                res[r][c] = '.'
        backtrack(0)
        return  ans