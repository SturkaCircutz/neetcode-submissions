class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        lastc = {}
        res = []
        for i, c in enumerate(s):
            lastc[c] = i
        count = 0
        end = 0
        for i , c in enumerate(s):
            end = max(end, lastc[c])
            count +=1
            if end == i:
                res.append(count)
                count = 0
        return res
                