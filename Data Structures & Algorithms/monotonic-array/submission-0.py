class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        stack = []
        if len(nums) <= 1:
            return True
        res = nums[-1] - nums[0]
        if res > 0:
            for i in nums:
                if stack and stack[-1] > i:
                    return False
                stack.append(i)
            return True
        else:
            for i in nums:
                if stack and stack[-1] < i:
                    return False
                stack.append(i)
            return True
