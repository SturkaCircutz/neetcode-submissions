class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ''
        for s in strs:
            res += str(len(s)) + ',' + s
        return res 
    def decode(self, s: str) -> List[str]:
        l, r = 0, 0
        res = []
        while l < len(s):
            l = r
            while r < len(s) and s[r] != ',':
                r+=1
            num = s[l:r]
            res.append(s[r+1:r+int(num)+1])
            r = r + int(num)+1
            l = r
        return res
