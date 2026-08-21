class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        lastc = {}
        res = []
        for i, c in enumerate(s):
            lastc[c] = i
        end = 0
        count = 0
        for i, c in enumerate(s):
            end = max(end, lastc[c])
            count +=1
            if i == end:
                res.append(count)
                count = 0
        return res