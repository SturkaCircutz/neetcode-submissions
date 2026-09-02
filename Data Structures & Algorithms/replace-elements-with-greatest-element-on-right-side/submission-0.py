class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        imax = arr[-1]
        res = [0] * len(arr)
        for i in range(len(arr)-2, -1, -1):
            if arr[i] > imax:
                res[i] = imax
                imax = arr[i]
            else:
                res[i] = imax
        res[-1] = -1
        return res