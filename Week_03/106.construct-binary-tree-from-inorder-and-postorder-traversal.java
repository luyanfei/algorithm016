/*
 * @lc app=leetcode.cn id=106 lang=java
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
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private int pidx;
    private TreeNode build(int[] inorder, int[] postorder, int left, int right) {
        if (left > right) {
            return null;
        }
        int val = postorder[pidx];
        pidx--;
        int idx = -1;
        for (int i = 0; i < inorder.length; i++) {
            if (inorder[i] == val) {
                idx = i;
                break;
            }
        }
        TreeNode rightNode = build(inorder, postorder, idx + 1, right);
        TreeNode leftNode = build(inorder, postorder, left, idx - 1);
        TreeNode node = new TreeNode(val);
        node.left = leftNode;
        node.right = rightNode;
        return node;
    }
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        pidx = postorder.length - 1;
        return build(inorder, postorder, 0, inorder.length - 1);
    }
}
