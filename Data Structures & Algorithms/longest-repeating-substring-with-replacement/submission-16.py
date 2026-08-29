class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        mp = defaultdict(int)
        maxlen = 0
        res = 0
        l = 0
        for r in range(len(s)):
            mp[s[r]]+=1
            maxlen = max(maxlen, mp[s[r]])
            if r - l +1 - maxlen > k:
                mp[s[l]]-=1
                l +=1
                continue
            res = max(res, r-l+1)
        return res