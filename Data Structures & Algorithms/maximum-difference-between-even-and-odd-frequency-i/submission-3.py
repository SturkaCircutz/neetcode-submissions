class Solution:
    def maxDifference(self, s: str) -> int:
        count = Counter(s)
        maxeven, maxodd = float('inf'), 0
        res = 0
        for v in count.values():
            if v % 2 == 0:
                maxeven = min(maxeven, v)
            else:
                maxodd = max(maxodd, v)
        return maxodd - maxeven