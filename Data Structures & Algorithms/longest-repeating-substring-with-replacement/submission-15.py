class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        mp = defaultdict(int)
        l = 0
        which = 0
        ans = 0
        for i in range(len(s)):
            mp[s[i]]+=1
            which = max(mp[s[i]], which)
            if i - l +1 - which > k:
                mp[s[l]]-=1
                l+=1
                continue
            ans = max(ans, i-l+1)
        return ans