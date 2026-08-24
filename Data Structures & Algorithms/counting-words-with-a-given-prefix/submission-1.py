class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        res = 0
        for w in words:
            res+=w.startswith(pref)
        return res