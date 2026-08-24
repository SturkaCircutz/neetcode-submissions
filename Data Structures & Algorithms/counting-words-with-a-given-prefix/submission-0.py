class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        size = len(pref)
        count = 0
        for i in range(len(words)):
            words[i] = words[i][:size]
        for w in words:
            if w == pref:
                count +=1
        return count