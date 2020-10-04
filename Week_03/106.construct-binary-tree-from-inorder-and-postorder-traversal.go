/*
 * @lc app=leetcode.cn id=106 lang=golang
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (69.73%)
 * Total Accepted:    60.3K
 * Total Submissions: 85.5K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
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
func buildTree(inorder []int, postorder []int) *TreeNode {
    imap := map[int]int{}
    for idx, val := range inorder {
        imap[val] = idx
    }
    postidx := len(postorder) - 1

    var build func(ileft, iright int) *TreeNode
    build = func(ileft, iright int) *TreeNode {
        if ileft > iright {
            return nil
        }
        nodeval := postorder[postidx]
        postidx--
        inidx := imap[nodeval]
        right := build(inidx + 1, iright)
        left := build(ileft, inidx - 1)
        return &TreeNode{Val: nodeval, Left: left, Right: right}
    }
    return build(0, len(inorder) - 1)
}
