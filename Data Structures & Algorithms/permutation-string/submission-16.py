class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        mp = defaultdict(int)
        mp2 = defaultdict(int)
        for i in s1:
            mp[ord(i) - ord('a')] = mp.get(ord(i)-ord('a'), 0) + 1
        for i in s2[:len(s1)]:
            mp2[ord(i) - ord('a')] = mp2.get(ord(i)-ord('a'), 0) + 1
        list0 = [0] * 26
        list1 = [0] * 26
        for i in range(26):
            list0[i] += mp[i]
            list1[i] += mp2[i]
        count = 0
        for i in range(26):
            if list0[i] == list1[i]:
                count +=1
        l = 0
        for j in range(len(s1), len(s2)):
            if count == 26:
                return True
            
            index = ord(s2[j]) - ord('a')
            list1[index]+=1
            if list0[index] == list1[index]:
                count +=1
            elif list0[index] +1 == list1[index]:
                count -=1
            
            index = ord(s2[l]) - ord('a')
            list1[index]-=1
            if list0[index] == list1[index]:
                count +=1
            elif list0[index] -1 == list1[index]:
                count -=1
            l+=1
        return count==26
            
