class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        count = Counter(nums)
        res = []
        for i, v in count.items():
            if v > math.floor(len(nums)//3):
               res.append(i)
        return res 