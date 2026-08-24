class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        set1 = {}
        set2 = {}
        for c in s:
            set1[c]=set1.get(c, 0) + 1
        for c in t:
            set2[c]=set2.get(c, 0) +1
        return set1 == set2