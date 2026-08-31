class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        stack = []
        n = len(nums)-1
        while k > 0:
            nums.insert(0, nums[n])
            nums.pop()
            k-=1
        print(nums)