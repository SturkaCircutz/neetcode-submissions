# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        left, right = float('-inf'), float('inf')
        def dfs(root, left, right):
            if left >= right:
                return False
            if not root:
                return True
            return dfs(root.left, left, root.val) and dfs(root.right, root.val, right)
        return dfs(root, left, right)