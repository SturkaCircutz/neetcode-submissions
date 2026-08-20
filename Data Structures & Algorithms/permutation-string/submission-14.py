class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        mp1 = {i : 0 for i in range(26)}
        mp2 = {i : 0 for i in range(26)}
        if len(s1) > len(s2): return False
        for i in range(len(s1)):
            mp1[ord(s1[i]) - ord('a')] +=1
            mp2[ord(s2[i]) - ord('a')] +=1
        match = 0
        for i in range(len(mp1)):
            if mp1[i] == mp2[i]:
                match +=1
        l = 0
        for i in range(len(s1), len(s2)):
            if match == 26:
                return True
            idx = ord(s2[i]) - ord('a')
            mp2[idx] +=1
            if mp1[idx] == mp2[idx]:
                match+=1
            elif mp1[idx] +1 == mp2[idx]:
                match-=1
            
            idx = ord(s2[l]) - ord('a')
            mp2[idx] -=1
            if mp1[idx] == mp2[idx]:
                match+=1
            elif mp1[idx] -1 == mp2[idx]:
                match-=1
            l+=1
        return match==26
            
        
        