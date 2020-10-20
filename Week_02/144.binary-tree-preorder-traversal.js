/*
 * @lc app=leetcode.cn id=144 lang=javascript
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
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var preorderTraversal = function(root) {
    let result = []
    while (root !== null) {
        if (root.left === null) {
            result.push(root.val)
            root = root.right
            continue
        }
        let pre = root.left
        while (pre.right !== null && pre.right !== root) {
            pre = pre.right
        }
        if (pre.right === null) {
            result.push(root.val)
            pre.right = root
            root = root.left
        } else {
            pre.right = null
            root = root.right
        }
    }
    return result
};
