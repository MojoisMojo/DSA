# Definition for a binary tree node.
from typing import Optional,List
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        
        def dfs(first:int,second:int,node:TreeNode|None) -> int:
            if node is None: return 0
            first,second = (node.val + second),first
            return max(dfs(first,second,node.left),dfs(first,second,node.left))
        return dfs(0,0,root)