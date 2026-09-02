class Solution:
    def generateParenthesis(self, n: int) -> List[str]:

        res, curr = [], []
        def dfs(leftn, rightn):
            if leftn == rightn == n:
                copy = ''.join(curr)
                res.append(copy)
                return

            if leftn < n:
                curr.append('(')
                dfs(leftn + 1, rightn)
                curr.pop()
            if leftn > rightn:
                curr.append(')')
                dfs(leftn, rightn + 1)
                curr.pop()
        dfs(0, 0)
        return res