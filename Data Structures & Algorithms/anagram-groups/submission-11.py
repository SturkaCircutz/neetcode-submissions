class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = defaultdict(list)
        for s in strs:
            key = [0] * 26
            for c in s:
                key[ord(c) - ord('a')]+=1
            keystr = ''
            for i in range(26):
                keystr += ','+str(key[i])
            mp[keystr].append(s)
        return list(mp.values())