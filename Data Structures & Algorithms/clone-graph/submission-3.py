"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        q = deque()
        mp = {}
        mp[node] = Node(node.val)
        q.append(node)
        while q :
            front = q.popleft()
            for nei in front.neighbors:
                if nei not in mp:
                    mp[nei] = Node(nei.val)
                    q.append(nei)
                mp[front].neighbors.append(mp[nei])
                
        return mp[node]
        