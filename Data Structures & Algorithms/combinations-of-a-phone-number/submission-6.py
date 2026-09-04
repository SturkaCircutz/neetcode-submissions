class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        mp = {
            '2' : 'abc',
            '3': "def",
            '4': "ghi",
            '5':"jkl",
            '6':'mno',
            '7':"pqrs",
            '8':"tuv",
            '9':"wxyz",
        }
        curr, res = [], []
        if not digits:
            return []
        def dfs(i):
            if len(digits) == i:
                copy = ''.join(curr.copy())
                res.append(copy)
                return
            for j in mp[digits[i]]:
                curr.append(j)
                dfs(i+1)
                curr.pop()
        dfs(0)
        return res