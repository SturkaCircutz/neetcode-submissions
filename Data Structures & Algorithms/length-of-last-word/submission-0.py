class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        nlist= s.split(' ')

        while nlist and nlist[-1] == '':
            nlist.pop()
        return len(nlist[-1])