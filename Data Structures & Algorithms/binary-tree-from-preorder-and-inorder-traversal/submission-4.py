# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        def build(l, r):
            if self.i == len(preorder):
                return
            if l > r:
                return 
            index = mp[preorder[self.i]]
            node = TreeNode(inorder[index])
            self.i += 1
            node.left = build(l, index-1)
            node.right = build(index+1, r)
            return node
        self.i = 0
        mp = {}
        for i in range(len(inorder)):
            mp[inorder[i]] = i
        return build(0, len(preorder)-1)


