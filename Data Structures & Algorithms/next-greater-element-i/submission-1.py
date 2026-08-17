class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        mp = {n:i for i, n in enumerate(nums1)}
        stack = []
        res = [-1] * len(nums1)
        for i in range(len(nums2)):
            curr = nums2[i]
            while stack and curr> stack[-1]:
                val = stack.pop()
                idx = mp[val]
                res[idx] = curr
            if curr in nums1:
                stack.append(curr)
        return res
