/*
 * @lc app=leetcode.cn id=105 lang=golang
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (67.99%)
 * Total Accepted:    115.7K
 * Total Submissions: 170.1K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
func indexOf(nums []int, k int) int {
    for i := 0; i < len(nums); i++ {
        if nums[i] == k {
            return i
        }
    }
    return -1
}
func buildTree(preorder []int, inorder []int) *TreeNode {
    var build func(pleft, pright, ileft, iright int) *TreeNode
    build = func(pleft, pright, ileft, iright int) *TreeNode {
        if pleft >= pright {
            return nil
        }
        val := preorder[pleft]
        idx := indexOf(inorder, val)
        left := build(pleft + 1, pleft + 1 + idx - ileft, ileft, idx)
        right := build(pleft + 1 + idx - ileft, pright, idx + 1, iright)
        return &TreeNode{Val: val, Left: left, Right: right}
    }
    return build(0, len(preorder), 0, len(inorder))
}
