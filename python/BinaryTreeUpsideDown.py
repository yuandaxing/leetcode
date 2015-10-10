class Solution:
    # @param root, a tree node
    # @return root of the upside down tree
    def upsideAux(self, root, left, right) :
        if not left :
            return root 
        v = self.upsideAux(left, left.left, left.right)
        root.left, root.right = None, None
        left.left, left.right = right, root
        return v
    
    def upsideDownBinaryTree(self, root):
        return None if not root else self.upsideAux(root, root.left,
                                                    root.right)

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    def visit(self) :
        print self.val
        if self.left :
            self.left.visit()
        if self.right :
            self.right.visit()

t1, t2 = TreeNode(1), TreeNode(2)
t1.left = t2
sol = Solution()
sol.upsideDownBinaryTree(t1).visit()
