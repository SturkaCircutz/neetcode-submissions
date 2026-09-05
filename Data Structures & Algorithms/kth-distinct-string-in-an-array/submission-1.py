class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        mp = {}
        for i in range(len(arr)):
            if arr[i] in mp:
                mp[arr[i]] = -1
            else:
                mp[arr[i]] = i
        rank = [key for key, value in mp.items() if value != -1]
        return rank[k-1] if len(rank) >= k else ""


