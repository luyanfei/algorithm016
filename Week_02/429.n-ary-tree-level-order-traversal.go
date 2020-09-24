/*
 * @lc app=leetcode.cn id=429 lang=golang
 *
 * [429] N-ary Tree Level Order Traversal
 *
 * https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (66.42%)
 * Total Accepted:    29.2K
 * Total Submissions: 44K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * 给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。
 * 
 * 例如，给定一个 3叉树 :
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 返回其层序遍历:
 * 
 * [
 * ⁠    [1],
 * ⁠    [3,2,4],
 * ⁠    [5,6]
 * ]
 * 
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 树的深度不会超过 1000。
 * 树的节点总数不会超过 5000。
 * 
 */
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func levelOrder(root *Node) [][]int {
    result := make([][]int, 0, 1000)
    if root == nil {
        return result;
    }
    q := []*Node{root}
    for len(q) > 0 {
        size := len(q)
        item := make([]int, 0, size)
        for i := 0; i < size; i++ {
            item = append(item, q[i].Val)
            for _, child := range q[i].Children {
                q = append(q, child)
            }
        }
        result = append(result, item)
        q = q[size:]
    }
    return result
}
