/*
 * @lc app=leetcode.cn id=94 lang=javascript
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
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function(root) {
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
            pre.right = root
            root = root.left
        } else {
            result.push(root.val)
            pre.right = null
            root = root.right
        }
    }
    return result
};
