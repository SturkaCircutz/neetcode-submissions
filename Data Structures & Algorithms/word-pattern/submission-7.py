class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        s = s.split()
        mp = {}
        mp1 = {}
        if len(s) != len(pattern): return False
        for i in range(len(pattern)):
            if (pattern[i] in mp and mp[pattern[i]] != s[i]) or (s[i] in mp1 and mp1[s[i]] != pattern[i]):
                return False
            mp[pattern[i]] = s[i]
            mp1[s[i]] = pattern[i]
        return True