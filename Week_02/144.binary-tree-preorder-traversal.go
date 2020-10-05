/*
 * @lc app=leetcode.cn id=144 lang=golang
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (66.75%)
 * Total Accepted:    168.6K
 * Total Submissions: 252.2K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 前序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [1,2,3]
 * 
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func preorderTraversal(root *TreeNode) []int {
    result := []int{}
    for root != nil {
        if root.Left == nil {
            result = append(result, root.Val)
            root = root.Right
            continue
        }
        pre := root.Left
        for pre.Right != nil && pre.Right != root {
            pre = pre.Right
        }
        if pre.Right == nil {
            result = append(result, root.Val)
            pre.Right = root
            root = root.Left
        } else {
            pre.Right = nil
            root = root.Right
        }
    }
    return result
}
