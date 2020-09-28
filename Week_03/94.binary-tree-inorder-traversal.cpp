/*
 * @lc app=leetcode.cn id=94 lang=cpp
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
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        while (root != nullptr) {
            if (root->left == nullptr) {
                result.emplace_back(root->val);
                root = root->right;
                continue;
            }
            TreeNode* pre = root->left;
            while (pre->right != nullptr && pre->right != root) {
                pre = pre->right;
            }
            if (pre->right == nullptr) {
                pre->right = root;
                root = root->left;
            } else {
                result.emplace_back(root->val);
                pre->right = nullptr;
                root = root->right;
            }
        }
        return result;
    }
};
