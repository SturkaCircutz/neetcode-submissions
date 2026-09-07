class StockSpanner:

    def __init__(self):
        self.stack = []

    def next(self, price: int) -> int:
        sta = self.stack.copy()
        count = 1
        if sta:
            while sta and sta[-1] <= price:
                count +=1
                sta.pop()
        self.stack.append(price)
        return count


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)