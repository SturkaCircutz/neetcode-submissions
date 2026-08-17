class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        mp = {}
        res = []
        for i in range(len(nums2)):
            mp[nums2[i]] = i
        for i in range(len(nums1)):
            curr = nums1[i]
            idx = mp[curr]
            res.append(-1)
            for j in range(idx+1, len(nums2)):
                if nums2[j] > curr:
                    res[-1] = nums2[j]
                    break
        return res