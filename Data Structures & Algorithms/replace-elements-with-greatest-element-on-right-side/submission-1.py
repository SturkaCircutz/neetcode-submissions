class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        maxres = -1
        for i in range(len(arr)-1, -1, -1):
            
            prefix = arr[i]
            arr[i] = maxres
            maxres = max(maxres, prefix)
            
        
        return arr