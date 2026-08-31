class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        count = Counter(nums)
        newset = list(count)
        for i in range(len(newset)):
            nums[i] = newset[i]
        nums = nums[:len(newset)]
        print(nums)
        return len(nums)