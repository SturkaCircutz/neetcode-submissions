class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        res = [0] * len(temperatures)
        for t in range(len(temperatures)):
            while stack and stack[-1][0] < temperatures[t]:
                res[stack[-1][1]] =  t - stack[-1][1]
                stack.pop()

            stack.append((temperatures[t], t))
        return res