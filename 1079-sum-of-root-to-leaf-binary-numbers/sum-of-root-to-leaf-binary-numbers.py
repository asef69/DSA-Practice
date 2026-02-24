# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        def helper(root,binary):
            if not root:
                return 0
            binary+=str(root.val)
            if not root.left and not root.right:
                return int(binary,2)

            return helper(root.left,binary)+helper(root.right,binary)

        return helper(root,"")            
        