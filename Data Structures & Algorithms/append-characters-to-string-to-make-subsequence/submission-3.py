class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        ls, lt = 0, 0
        curr = 0
        while ls < len(s):
            if lt < len(t) and s[ls] == t[lt]:
                curr +=1
                lt +=1
            ls +=1


        return len(t) - curr