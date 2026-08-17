class Solution:
    def compress(self, chars: List[str]) -> int:
        l, r = 0, 0
        k = 0
        while l < len(chars):
            chars[k] = chars[l]
            r+=1
            k+=1
            while r < len(chars) and chars[r] == chars[l]:
                r+=1
            if r - l>1:
                for i in str(r-l):
                    chars[k] = i
                    k+=1
            l = r     
        return k
