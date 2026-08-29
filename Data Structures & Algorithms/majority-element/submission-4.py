class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        res = 0
        for r in range(len(nums)):
            if count == 0:
                res = nums[r]
            count += 1 if res == nums[r] else -1
     
        return res
