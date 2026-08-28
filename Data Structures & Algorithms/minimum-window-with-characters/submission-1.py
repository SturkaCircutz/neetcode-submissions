class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if t == '': return ''
        countT , window= {}, {}
        for i in t:
            countT[i] = countT.get(i, 0) + 1
        res, resLen = [-1, -1], float('inf')
        l = 0
        match = 0
        r = 0
        while r < len(s):
            c = s[r]
            window[c] = window.get(c, 0) + 1
            if c in countT and window[c] == countT[c]:
                match +=1
            while match == len(countT):
                if r - l + 1 < resLen:
                    res = [l, r]
                    resLen = r - l +1
                window[s[l]]-=1
                if s[l] in countT and countT[s[l]] > window[s[l]]:
                    match -=1
                l+=1
            r +=1
        l, r = res
        return s[l : r+1] if resLen != float('inf') else ''

                