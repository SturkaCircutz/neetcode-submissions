class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        l, r = max(weights), sum(weights)
        res = 0
        while l <= r:
            mid = (l+r) // 2
            i = 0
            count = 1
            tmp = mid
            while i < len(weights):
                if mid - weights[i] < 0:
                    count += 1
                    mid = tmp
                mid -= weights[i]
                i+=1
            mid = tmp
            if count <= days:
                res = mid
                r = mid - 1
            else:
                l = mid +1
        return res