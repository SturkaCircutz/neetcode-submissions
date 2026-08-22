"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        mp = {}
        if not node:
            return None
        copy = Node(node.val)
        mp[node] = copy 
        q = deque([node])
        while q:
            curr = q.popleft()
            for i in curr.neighbors:
                if i not in mp:
                    copy = Node(i.val)
                    mp[i] = copy
                    q.append(i)
                mp[curr].neighbors.append(mp[i])
        return mp[node]