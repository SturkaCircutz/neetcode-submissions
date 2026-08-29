class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)
        ans = 0
        while l <= r:
            eatrate = (l+r) //2
            res = 0
            for i in piles:
                res += math.ceil(i / eatrate)
            if res <= h:
                ans = eatrate
                r = eatrate -1
            else:
                l = eatrate+ 1
        
        return ans