class Solution:
    def removeElement(self, s: List[int], val: int) -> int:
        l = 0
        count = 0
        for r in range(len(s)):
            if s[r] != val:
                count +=1
                s[l], s[r] = s[r], s[l]
                l+=1
            r+=1
        s = s[:count]
        return len(s)
        