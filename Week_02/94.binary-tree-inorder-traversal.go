/*
 * @lc app=leetcode.cn id=94 lang=golang
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (72.75%)
 * Total Accepted:    262.5K
 * Total Submissions: 357K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
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
 * 输出: [1,3,2]
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
func inorderTraversal(root *TreeNode) []int {
    result := make([]int, 0, 100)
    var tranverse func(node *TreeNode)
    tranverse = func(node *TreeNode) {
        if node == nil {
            return
        }
        tranverse(node.Left)
        result = append(result, node.Val)
        tranverse(node.Right)
    }
    tranverse(root)
    return result
}
