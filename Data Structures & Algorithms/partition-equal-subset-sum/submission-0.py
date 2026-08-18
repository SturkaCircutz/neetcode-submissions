class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if sum(nums) %2 != 0:
            return False
        tar = sum(nums)//2
        dp = set()
        dp.add(0)
        for i in range(len(nums)):
            newdp = set()
            for d in dp:
                newdp.add(d+nums[i])
                newdp.add(d)
            dp = newdp
        if tar in dp:
            return True
        return False
                
                

