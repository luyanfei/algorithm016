/*
 * @lc app=leetcode.cn id=106 lang=cpp
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
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pidx = (int)postorder.size() - 1;
        function<TreeNode*(int, int)> build = [&] (int ileft, int iright) -> TreeNode* {
            if (ileft >= iright) {
                return nullptr;
            }
            TreeNode* node = new TreeNode(postorder[pidx]);
            int inidx = -1;
            for (int i = 0; i < inorder.size(); i++) {
                if (inorder[i] == node->val) {
                    inidx = i;
                    break;
                }
            }
            pidx--;
            node->right = build(inidx + 1, iright);
            node->left = build(ileft, inidx);
            return node;
        };
        return build(0, (int)inorder.size());
    }
};
