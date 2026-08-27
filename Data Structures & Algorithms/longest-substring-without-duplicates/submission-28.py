class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        mp = defaultdict(int)
        res = 0
        l = 0
        for i in range(len(s)):
            while s[i] in mp:
                mp[s[l]]-=1
                if mp[s[l]] == 0:
                    del mp[s[l]]
                l+=1

            mp[s[i]]+=1
            res = max(res, i - l +1)
        
        return res
