class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        mp1 = defaultdict(int)
        mp2 = defaultdict(int)
        for i in s:
            mp1[i] = mp1.get(i, 0) + 1
        for j in t:
            mp2[j] = mp2.get(j, 0) + 1
        return mp1 == mp2