class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        count = defaultdict(int)
        res = []
        for i in range(len(nums)):
            count[nums[i]]+=1
            if len(count) > 2:
                newcount = defaultdict(int)
                for k, v in count.items():
                    if v > 1:
                        newcount[k] = v - 1
                count = newcount

        for k,v in count.items():
            if nums.count(k) > len(nums) // 3:
                res.append(k)
        return res