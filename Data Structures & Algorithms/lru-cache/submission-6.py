class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.dic = OrderedDict()

    def get(self, key: int) -> int:
        if key in self.dic:
            self.dic.move_to_end(key)
        else:
            return -1
        return self.dic[key]

    def put(self, key: int, value: int) -> None:

        if key in self.dic:
            self.dic.move_to_end(key)
        self.dic[key] = value
        if len(self.dic) > self.cap:
            self.dic.popitem(last = False)

