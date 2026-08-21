class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        prices = [float('inf')] * n
        prices[src] = 0
        for i in range(k+1):
            tmpprices = prices.copy()
            for s, d, k in flights:
                if tmpprices[s] == float('inf'):
                    continue
                if prices[s] + k< tmpprices[d]:
                    tmpprices[d] = prices[s]+k
            prices = tmpprices
        return -1 if prices[dst] == float('inf') else prices[dst]
