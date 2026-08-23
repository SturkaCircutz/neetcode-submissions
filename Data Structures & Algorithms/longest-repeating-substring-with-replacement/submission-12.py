class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        mp = defaultdict(int)

        l, r = 0, 0
        res = 0
        while r < len(s):
            mp[s[r]]+=1
            r+=1
            ov = 0
            key = 0
            for t,v in mp.items():
                if v > ov:
                    key = max(key, v)
            if r - l - key > k:
                mp[s[l]]-=1 
                l+=1
            res = max(res, r-l)
        return res


