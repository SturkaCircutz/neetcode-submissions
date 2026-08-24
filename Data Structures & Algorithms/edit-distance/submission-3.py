class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        mp = [[0 for i in range(len(word1)+1)] for j in range(len(word2)+1)]
        for i in range(len(word1)+1):
            mp[len(word2)][i] = len(word1) - i
        for j in range(len(word2)+1):
            mp[j][len(word1)] = len(word2) - j
        for i in range(len(word2)-1, -1, -1):
            for j in range(len(word1)-1, -1, -1):
                if word1[j] != word2[i]:
                    mp[i][j] = min(mp[i+1][j], mp[i][j+1], mp[i+1][j+1]) + 1
                    continue
                mp[i][j] = mp[i+1][j+1]


        return mp[0][0]
        