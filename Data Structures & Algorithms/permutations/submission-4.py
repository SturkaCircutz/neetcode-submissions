class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 0:
            return [[]]
        permutes = self.permute(nums[1:])
        curr = []
        for p in permutes:
            for i in range(len(p)+1):
                copy = p.copy()
                copy.insert(i, nums[0])
                curr.append(copy)
        return curr