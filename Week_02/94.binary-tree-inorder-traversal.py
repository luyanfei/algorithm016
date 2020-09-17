#
# @lc app=leetcode.cn id=94 lang=python3
#
# [94] Binary Tree Inorder Traversal
#
# https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
#
# algorithms
# Medium (72.75%)
# Total Accepted:    262.5K
# Total Submissions: 357K
# Testcase Example:  '[1,null,2,3]'
#
# 给定一个二叉树，返回它的中序 遍历。
# 
# 示例:
# 
# 输入: [1,null,2,3]
# ⁠  1
# ⁠   \
# ⁠    2
# ⁠   /
# ⁠  3
# 
# 输出: [1,3,2]
# 
# 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
# 
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

def inorder(root, result):
    if not root:
        return
    inorder(root.left, result)
    result.append(root.val)
    inorder(root.right, result)

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        result = []
        inorder(root, result)
        return result
