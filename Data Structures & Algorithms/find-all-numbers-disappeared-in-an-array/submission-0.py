class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        mp = {}
        for i in range(1, len(nums)+1):
            mp[i]=0
        for i in range(1, len(nums)+1):
            if i in nums:
                mp[i]+=1
        res = []
        for k,v in mp.items():
            if v != 1:
                res.append(k)
        return res