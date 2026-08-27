class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ''
        for s in strs:
            res+=str(len(s))+','+ s
        return res
    def decode(self, s: str) -> List[str]:
        res = []
        l, r = 0, 0
        while r < len(s):
            l = r
            while r < len(s) and s[r] != ',':
                r+=1
            num = int(s[l:r])
            res.append(s[r+1:r+num+1])
            r = r + num + 1
        return res

