class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l , r = 1, max(piles)
        while l < r:
            mid = (l+r) //2
            res = 0
            for i in piles:
                if i <= mid:
                    res +=1
                    continue
                res += (i + mid -1 ) // mid
            if res <= h:
                r = mid
            else:
                l = mid+1
        return l
                


