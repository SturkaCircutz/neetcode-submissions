class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        res = [0]*len(temperatures)
        stack = []
        for i in range(len(temperatures)):
            while stack and temperatures[i] > stack[-1][0]:
                j = stack[-1][1]
                res[stack.pop()[1]] = i - j
            stack.append((temperatures[i], i))
        return res
