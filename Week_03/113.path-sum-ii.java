/*
 * @lc app=leetcode.cn id=113 lang=java
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (60.98%)
 * Total Accepted:    92K
 * Total Submissions: 150.8K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
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
    List<List<Integer>> result = new ArrayList<>();
    List<Integer> item = new ArrayList<>();
    public void build(TreeNode root, int sum) {
        if (root == null) return;
        item.add(root.val);
        if (root.left == null && root.right == null) {
            if (sum - root.val == 0)
                result.add(new ArrayList<>(item));
            item.remove(item.size() - 1);
            return;
        }
        if (root.left != null)
            build(root.left, sum - root.val);
        if (root.right != null)
            build(root.right, sum - root.val);
        item.remove(item.size() - 1);
    }
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        build(root, sum);
        return result;
    }
}
