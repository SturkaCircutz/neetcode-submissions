class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        stack = []
        maxi = 0
        l = 0
        while l < len(nums):
            if stack and stack[-1][0] >= nums[l]:
                maxi = max(maxi, len(stack))
                stack = []
            stack.append((nums[l], l))
            l+=1
        maxi = max(maxi, len(stack))
        stack = []
        l=0
        mini = 0
        while l < len(nums):
            if stack and stack[-1][0] <= nums[l]:
                mini = max(mini, len(stack))
                stack = []
            stack.append((nums[l], l))
            l+=1
        mini = max(mini, len(stack))
        return max(mini, maxi)
