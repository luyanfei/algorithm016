/*
 * @lc app=leetcode.cn id=515 lang=golang
 *
 * [515] 在每个树行中找最大值
 *
 * https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (61.99%)
 * Total Accepted:    18.4K
 * Total Submissions: 29.7K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * 您需要在二叉树的每一行中找到最大的值。
 * 
 * 示例：
 * 
 * 
 * 输入: 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      / \   \  
 * ⁠     5   3   9 
 * 
 * 输出: [1, 3, 9]
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
func largestValues(root *TreeNode) []int {
    q := []*TreeNode{root}
    result := []int{}
    if root == nil {
        return result
    }
    for len(q) > 0 {
        maxval := q[0].Val
        for i := 1; i < len(q); i++ {
            if q[i].Val > maxval {
                maxval = q[i].Val
            }
        }
        result = append(result, maxval)
        newq := make([]*TreeNode, 0, 2 * len(q))
        for _, node := range q {
            if node.Left != nil {
                newq = append(newq, node.Left)
            }
            if node.Right != nil {
                newq = append(newq, node.Right)
            }
        }
        q = newq
    }
    return result
}
