#
# @lc app=leetcode.cn id=144 lang=python3
#
# [144] Binary Tree Preorder Traversal
#
# https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
#
# algorithms
# Medium (66.75%)
# Total Accepted:    168.6K
# Total Submissions: 252.2K
# Testcase Example:  '[1,null,2,3]'
#
# 给定一个二叉树，返回它的 前序 遍历。
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
# 输出: [1,2,3]
# 
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

class Solution:
    def preorder(self, root, result):
        if root is None:
            return
        result.append(root.val)
        self.preorder(root.left, result)
        self.preorder(root.right, result)

    def preorderTraversal(self, root: TreeNode) -> List[int]:
        result = []
        self.preorder(root, result)
        return result
