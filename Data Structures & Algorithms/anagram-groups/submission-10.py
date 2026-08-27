class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = defaultdict(list)
        for s in strs:
            dic = defaultdict(int)
            for c in s:
                dic[ord(c)-ord('a')] = dic.get(ord(c)-ord('a'), 0) + 1
            
            key = ''
            for i in range(0, 26):
                key += ','+str(dic[i])
            res[key].append(s)
        return list(res.values())
            
        

