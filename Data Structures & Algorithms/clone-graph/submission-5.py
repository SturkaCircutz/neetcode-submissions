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
            return
        copy = Node(node.val)
        mp[node] = copy
        q = deque([node])
        while q:
            front = q.popleft()
            for nei in front.neighbors:
                if nei not in mp:
                    mp[nei]= Node(nei.val)
                    q.append(nei)
                mp[front].neighbors.append(mp[nei])
        return mp[node]