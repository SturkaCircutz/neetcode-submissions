class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res, curr = [], []
        def dfs(openN, closeN):
            if openN == closeN == n:
                copy = ''.join(curr)
                res.append(copy)
            if openN < n:
                curr.append('(')
                dfs(openN+1, closeN)
                curr.pop()
            if openN > closeN:
                curr.append(')')
                dfs(openN, closeN+1)
                curr.pop()
        dfs(0, 0)
        return res