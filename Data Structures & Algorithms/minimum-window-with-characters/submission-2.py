class Solution:
    def minWindow(self, s: str, t: str) -> str:
        
        maxlen, rangem = float('inf'), [-1, -1]
        CountT = Counter(t)
        mp = {}
        match = 0
        l = 0
        for i in range(len(s)):
            mp[s[i]] = mp.get(s[i], 0) + 1
            if s[i] in CountT and CountT[s[i]] == mp[s[i]]:
                match +=1
            
            while match == len(CountT):
                if i - l + 1 < maxlen:
                    maxlen = i - l +1
                    rangem = [l, i]
                
                mp[s[l]] -=1
                if s[l] in CountT and mp[s[l]] < CountT[s[l]]:
                    match -=1
                l+=1
        l, r = rangem
        return s[l:r+1] if maxlen != float('inf') else ''
                    
