class Solution:
    def climbStairs(self, n: int) -> int:
        one, two = 1, 2
        if n <=2:
            return n
        for i in range(n-2):
            three = one + two
            one = two
            two = three
        return two