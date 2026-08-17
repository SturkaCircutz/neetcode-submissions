class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ndic = defaultdict(list)
        res = []
        for s in strs:
            dic = [0]*26
            for c in s:
                dic[ord(c) - ord('a')]+=1

            key = ''
            for i in range(26):
                key += ','+str(dic[i])
            ndic[tuple(key)].append(s)
        return list(ndic.values())
