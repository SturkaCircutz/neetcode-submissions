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
        def dfs(i, child):
            curr = child
            for j in range(i, len(word)):
                if word[j] == '.':
                    for nei in curr.children.values():
                        if dfs(j+1, nei):
                            return True
                    return False
                else:
                    if word[j] not in curr.children:
                        return False
                    curr = curr.children[word[j]]
            return curr.endword

        return dfs(0, curr) 