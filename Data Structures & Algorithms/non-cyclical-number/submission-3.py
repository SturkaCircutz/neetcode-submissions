class Solution:
    def isHappy(self, n: int) -> bool:
        visit = set()
        while n not in visit:
            visit.add(n)
            n = self.check(n)
            if n == 1:
                return True
        return False
    def check(self, n):
        res = 0
        while n:
            digit = n % 10
            res += digit ** 2
            n = n //10
        return res

