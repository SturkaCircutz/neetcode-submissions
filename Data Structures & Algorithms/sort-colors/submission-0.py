class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        bucket = [0]*3
        count = 0
        for i in nums:
            bucket[i]+=1
        for i in range(3):
            for j in range(bucket[i]):
                nums[count] = i
                count+=1
        
        