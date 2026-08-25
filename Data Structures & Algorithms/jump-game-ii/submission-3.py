class Solution:
    def jump(self, nums: List[int]) -> int:
        left, right = 0, 0
        count = 0
        while right < len(nums)-1:
            newright = right
            for i in range(left, right+1):
                newright= max(newright, i+ nums[i])
            left = right+1
            right = newright
            count +=1
        return count