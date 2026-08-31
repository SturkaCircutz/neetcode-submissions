class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res = 0
        prefixsum = {0 : 1}
        curnum = 0
        for n in nums:
            curnum += n
            req = curnum - k
            res += prefixsum.get(req, 0)
            prefixsum[curnum] = 1 + prefixsum.get(curnum, 0)
        
        return res