class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        maxres = 0
        for i in range(len(heights)):
            start = i
            while stack and stack[-1][1] > heights[i]:
                maxres = max(maxres, stack[-1][1]*(i - stack[-1][0]))
                start = stack[-1][0]
                stack.pop()
            stack.append((start, heights[i]))

        for i, item in stack:
            maxres = max(maxres, (len(heights)-i) * item)
        return maxres