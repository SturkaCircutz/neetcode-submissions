class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        res= []
        container = set(words)
        tmp = container.copy()
        for w in words:
            container.remove(w)
            while container:
                if w in container.pop():
                    res.append(w)
                    break
            container = tmp.copy()
        return res
                
            