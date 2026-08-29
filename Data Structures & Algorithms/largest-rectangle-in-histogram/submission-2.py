class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        maxlen, r = 0, 0
        while r < len(heights):
            start = r
            while stack and stack[-1][0] > heights[r]:
                maxlen = max(maxlen, (r - stack[-1][1]) * stack[-1][0])
                start = stack[-1][1]
                stack.pop()
            stack.append((heights[r], start))
            r+=1
        
        for h, i in stack:
            maxlen = max(maxlen, (len(heights)-i) * h)
        return maxlen