class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        def rob2(li):
            n = len(li) 
            mp = [0] * n
            if n == 1:
                return li[0]
            mp[0] = li[0]
            mp[1] = max(li[0], li[1])
            for i in range(2, n):
                mp[i] = max(mp[i-1], mp[i-2] + li[i])
            return mp[n-1]
        return max(rob2(nums[1:]), rob2(nums[:len(nums)-1]))

        