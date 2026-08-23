class node:
    def __init__(self):
        self.children = {}
        self.endword = False
class WordDictionary:

    def __init__(self):
        self.root = node()

    def addWord(self, word: str) -> None:
        curr = self.root
        for w in word:
            if w not in curr.children:
                curr.children[w] = node()
            curr = curr.children[w]
        curr.endword = True

    def search(self, word: str) -> bool:
        curr = self.root
        def dfs(j, child):
            curr = child
            for i in range(j, len(word)):
                if word[i] == '.':
                    for c in curr.children.values():
                        if dfs(i+1, c):
                            return True
                    return False
                else:
                    if word[i] not in curr.children:
                        return False
                    curr = curr.children[word[i]]
            return curr.endword
        return dfs(0, curr)
