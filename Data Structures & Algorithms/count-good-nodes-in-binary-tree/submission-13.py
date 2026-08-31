# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        
        def dfs(root, pre):
            if not root:
                return 0

            count = 0
            if root.val >= pre.val:
                count +=1
                pre = root
            count += dfs(root.left, pre)
            count += dfs(root.right, pre)
            return count
        return dfs(root, TreeNode(-1000))
        