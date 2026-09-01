class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.stack = nums

    def add(self, val: int) -> int:
        self.stack.append(val)
        self.stack.sort()
        return self.stack[-self.k]
