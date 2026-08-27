class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        mp1 = {i:0 for i in range(26)}
        mp2 = {i:0 for i in range(26)}
        if len(s2) < len(s1):
            return False
        count = 0
        for i in range(len(s1)):
            mp1[ord(s1[i])-ord('a')] += 1
            mp2[ord(s2[i])-ord('a')] += 1
        for i, k in mp1.items():
            if mp1[i] == mp2[i]:
                count +=1
        l = 0
        for i in range(len(s1), len(s2)):
            if count == 26:
                return True
            target = ord(s2[i])-ord('a')
            mp2[target]+=1
            if mp1[target] == mp2[target]:
                count +=1
            elif mp1[target]+1 == mp2[target]:
                count-=1
            
            target = ord(s2[l])-ord('a')
            mp2[target]-=1
            if mp1[target] == mp2[target]:
                count +=1
            elif mp1[target]-1 == mp2[target]:
                count-=1
            l+=1
        return count == 26
            