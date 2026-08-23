class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if sum(nums) % 2 == 1:
            return False
        res = sum(nums) // 2
        li = set()
        li.add(0)
        for i in nums:
            newli = set()
            for j in li:
                newli.add(j+i)
                newli.add(j)
            li = newli
        if res in li:
            return True
        return False