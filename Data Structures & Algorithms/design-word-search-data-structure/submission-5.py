class Node:
    def __init__(self):
        self.child = {}
        self.word = False
class WordDictionary:

    def __init__(self):
        self.root = Node()

    def addWord(self, word: str) -> None:
        curr = self.root
        for w in word:
            if w not in curr.child:
                curr.child[w] = Node()
            curr =  curr.child[w]
        curr.word = True

    def search(self, word: str) -> bool:
        curr = self.root
        def dfs(curr, i):
            for j in range(i, len(word)):
                if word[j] == '.':
                    for nei in curr.child.values():
                        if dfs(nei, j+1):
                            return True
                    return False
                else:
                    if word[j] not in curr.child:
                        return False
                    curr = curr.child[word[j]]
            return curr.word
        return dfs(curr, 0)
                    
