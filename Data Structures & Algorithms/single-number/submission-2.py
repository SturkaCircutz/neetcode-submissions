class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums = Counter(nums)
        for n, t in nums.items():
            if t == 1:
                return n
        