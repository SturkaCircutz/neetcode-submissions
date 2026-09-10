class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        count = 0
        mp = sorted(heights)
        for i in range(len(heights)):
            if heights[i] != mp[i]: 
                count +=1
        return count