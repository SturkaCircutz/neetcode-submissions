class Solution:
    def countSubstrings(self, s: str) -> int:
        res = 0
        for i in range(len(s)):
            l, r = i, i
            def ispali(l, r):
                res = 0
                while l >= 0 and r <len(s) and s[l] == s[r]:
                    res+=1
                    l-=1
                    r+=1
                return res
            res += ispali(l, r)
            l, r = i, i+1
            res+=ispali(l, r)
        return res