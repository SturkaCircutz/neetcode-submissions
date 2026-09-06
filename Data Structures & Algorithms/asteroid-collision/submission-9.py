class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        res = []
        for a in asteroids:
            add = True
            while stack and a < 0 and stack[-1] <= abs(a):
                equal = stack[-1] == abs(a)
                stack.pop()
                if equal:
                    add = False
                    break
            if a > 0:
                stack.append(a)
            if not stack and a < 0 and add:
                res.append(a)
                add = True
        return res + stack