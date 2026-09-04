class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        for i in range(len(flowerbed)):
            if flowerbed[i] == 1:
                if i + 1 < len(flowerbed):
                    flowerbed[i+1] = 2
                if i - 1 >= 0:
                    flowerbed[i-1] = 2
        count = 0
        i = 0
        while i < len(flowerbed):
            if flowerbed[i] == 0:
                count +=1
                i+=2
            else:
                i+=1
        return False if count < n else True
