class LRUCache:

    def __init__(self, capacity: int):
        self.dic = OrderedDict()
        self.cap = capacity

    def get(self, key: int) -> int:
        if key not in self.dic:
            return -1
        self.dic.move_to_end(key)
        return self.dic[key]

    def put(self, key: int, value: int) -> None:
        if key in self.dic:
            self.dic.move_to_end(key)
        self.dic[key] = value

        if self.cap < len(self.dic):
            self.dic.popitem(last = False)


        
        