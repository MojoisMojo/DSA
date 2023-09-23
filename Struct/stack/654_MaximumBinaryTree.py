from ... import *
# Definition for a binary tree node.
# 输入：nums = [3,2,1,6,0,5]
# 输出：[6,3,5,null,2,0,null,null,1]
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        st = []
        for n in nums:
            this_node = TreeNode(n)
            while st and n > st[-1].val:
                this_node.left = st.pop()
            if(st): st[-1].right = this_node
            st.append(this_node)
        return st[0]
# 4 7 3 2 1 6 0 5
# 
if __name__ == "__main__":
    pass