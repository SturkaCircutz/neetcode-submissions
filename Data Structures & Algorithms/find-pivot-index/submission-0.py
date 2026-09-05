class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        nums = [0] + nums
        for i in range(1, len(nums)):
            leftsum = sum(nums[:i])
            rightsum = sum(nums[i+1 : ])
            if leftsum == rightsum:
                return i-1
        return -1