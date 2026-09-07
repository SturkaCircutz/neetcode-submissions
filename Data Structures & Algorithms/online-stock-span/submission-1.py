class StockSpanner:

    def __init__(self):
        self.stack = []

    def next(self, price: int) -> int:
        sta = self.stack
        count = 1
        if sta:
            while sta and sta[-1][0] <= price:
                count += self.stack[-1][1]
                sta.pop()
        self.stack.append((price, count))
        return count


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)