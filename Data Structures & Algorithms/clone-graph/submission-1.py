"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        curr = node
        mp = {}
        def dfs(curr):
            if not curr: return
            if curr in mp:
                return mp[curr]
            new = Node(curr.val)
            mp[curr] = new
            for nei in curr.neighbors:
                new.neighbors.append(dfs(nei))
            return mp[curr]
        return dfs(curr)
        