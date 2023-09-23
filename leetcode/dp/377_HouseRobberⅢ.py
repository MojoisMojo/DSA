# Definition for a binary tree node.
from typing import Optional,List
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        
        def dfs(node:TreeNode|None) -> List[int]:
            if node is None: return [0,0]
            
            neighbor_l,interval_l = dfs(node.left)
            neighbor_r,interval_r = dfs(node.right)
            
            return [max(neighbor_l+neighbor_r,interval_l+interval_r+node.val),neighbor_l+neighbor_r]
        return dfs(root)[0] # why is [0] ? think about it 

if __name__ == "__main__":
    root = TreeNode(3,
                    left=TreeNode(2),
                    right=TreeNode(1,
                                    left=TreeNode(4),
                                    right=TreeNode(0)
                                    )
                    )
    print(Solution().rob(root))