class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l , i = 0, 0
        res = 0
        curr = set()
        while i < len(s):
            while s[i] in curr:
                curr.remove(s[l])
                l +=1
            if i - l + 1>res:
                res = max(res, i - l + 1)
            curr.add(s[i])
            i+=1
        return res