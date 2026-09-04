class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mp, mp1 = {}, {}
        for i in range(len(s)):
            if (s[i] in mp and mp[s[i]] != t[i]) or (t[i] in mp1 and mp1[t[i]] != s[i]):
                return False
            mp[s[i]] = t[i]
            mp1[t[i]] = s[i]

        return True
