class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        lt, ls = len(t)-1, len(s)-1
        while lt >= 0:
            if ls < 0:
                return True
            if s[ls] == t[lt]:
                ls -=1
                lt -=1
            else:
                lt -=1
            
            if ls < 0:
                return True
        return False
