class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s2) < len(s1):
            return False
        mp1 = {i : 0 for i in range(26)}
        mp2 = {i : 0 for i in range(26)}
        for i in range(len(s1)):
            mp1[ord(s1[i])-ord('a')]+=1
            mp2[ord(s2[i])-ord('a')]+=1
        count = 0
        for i in range(26):
            if mp1[i] == mp2[i]:
                count +=1
        l = 0
        for r in range(len(s1), len(s2)):
            if count == 26:
                return True
            
            c = ord(s2[r]) - ord('a')
            mp2[c]+=1
            if mp1[c] == mp2[c]:
                count +=1
            elif mp1[c]+1==mp2[c]:
                count -=1

            c = ord(s2[l]) - ord('a')
            mp2[c]-=1
            if mp1[c] == mp2[c]:
                count +=1
            elif mp1[c]-1==mp2[c]:
                count -=1
            l+=1
        return count == 26