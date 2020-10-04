/*
 * @lc app=leetcode.cn id=501 lang=golang
 *
 * [501] 二叉搜索树中的众数
 *
 * https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (48.44%)
 * Total Accepted:    34.4K
 * Total Submissions: 70.3K
 * Testcase Example:  '[1,null,2,2]'
 *
 * 给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
 * 
 * 假定 BST 有如下定义：
 * 
 * 
 * 结点左子树中所含结点的值小于等于当前结点的值
 * 结点右子树中所含结点的值大于等于当前结点的值
 * 左子树和右子树都是二叉搜索树
 * 
 * 
 * 例如：
 * 给定 BST [1,null,2,2],
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 返回[2].
 * 
 * 提示：如果众数超过1个，不需考虑输出顺序
 * 
 * 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
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
func findMode(root *TreeNode) []int {
    result := []int{}
    base, count, maxcount := 0, 0, 0
    update := func(val int) {
        if count == 0 {
            base = val
            count++
        } else if val == base {
            count++
        } else {
            base = val
            count = 1
        }
        if count > maxcount {
            maxcount = count
            result = []int{base}
        } else if count == maxcount {
            result = append(result, base)
        }
    }

    for root != nil {
        if root.Left == nil {
            update(root.Val)
            root = root.Right
            continue
        }
        pre := root.Left
        for pre.Right != nil && pre.Right != root {
            pre = pre.Right
        }
        if pre.Right == nil {
            pre.Right = root
            root = root.Left
        } else if pre.Right == root {
            update(root.Val)
            pre.Right = nil
            root = root.Right
        }
    }
    return result
}
